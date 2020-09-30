#include "Cloud.h"

#include <QtCore/QSharedPointer>
#include <QtCore/QTimerEvent>
#include <QtCore/QUuid>
#include <QtWebSockets/QWebSocket>

#include "DeviceState.h"
#include "ReplyTrack.h"
#include "ServiceFind.h"

#include "ZkgdLog.h"

Cloud::Cloud(QObject* parent)
    :mIsConnected(false)
    ,mReconnectionTimer(0)
{
    mWebSocketClient = new QWebSocket();
    mWebSocketClient->setParent(this);

    connect(mWebSocketClient, &QWebSocket::connected, this, &Cloud::connected);
    connect(mWebSocketClient, &QWebSocket::disconnected, this, &Cloud::reconnection);
    connect(mWebSocketClient, &QWebSocket::binaryMessageReceived, this, &Cloud::handleBinaryMessage);

    mServiceFind = new ServiceFind(this);
    connect(mServiceFind, &ServiceFind::serviceAddressChanged, this, &Cloud::serviceAddressChanged);

    mReplyTrack = new ReplyTrack(this);
}

Cloud::~Cloud()
{
}

void Cloud::connectCloud()
{
    qDebug() << "Opening " << mServiceFind->getServiceAddress();
    mIsConnected = true;
    mWebSocketClient->open(QUrl(mServiceFind->getServiceAddress()));
}

void Cloud::disconnectCloud()
{
    mIsConnected = false;
    mWebSocketClient->abort();
}

void Cloud::connected()
{
    qDebug() << "Connect Cloud Success";
    killTimer(mReconnectionTimer);

    reportOnline();
}

void Cloud::serviceAddressChanged()
{
    mWebSocketClient->abort();
    mWebSocketClient->open(QUrl(mServiceFind->getServiceAddress()));
}

void Cloud::reconnection()
{
    qDebug() << "Reconnection Cloud ...";
    if (mIsConnected)
    {
        mReconnectionTimer = startTimer(5000);
    }
}

void Cloud::timerEvent(QTimerEvent* event)
{
    if (mReconnectionTimer == event->timerId())
    {
        mWebSocketClient->open(QUrl(mServiceFind->getServiceAddress()));
    }
}

void Cloud::handleBinaryMessage(const QByteArray& message)
{
    SendData received_data;
    received_data.ParseFromString(std::string(message.constData(), message.length()));
    QString uuid = QString::fromStdString(received_data.serianum());

    if (received_data.action() == "connection_check") {
        responseConnectCheck(received_data);
    }
    else if (received_data.action() == "collect") {
        responseCollectCommand(received_data);

        //TODO: 执行相对应的动作
    }
    else if (received_data.type() == "reply") {
        mReplyTrack->removeTrack(uuid);
        ZKGDDEBUG(uuid << " get a reply: " << received_data.message());
    }
}

void Cloud::responseConnectCheck(const SendData& received_data)
{
    SendData data;
    data.set_serianum(received_data.serianum());
    data.set_type("reply");
    data.set_action(received_data.action());
    data.set_success("true");
    data.set_message(QString::fromLocal8Bit("成功").toUtf8().data());

    if (serializeSend(data)) {
        ZKGDDEBUG("Response Connect Check");
    }
}

bool Cloud::serializeSend(const SendData& data)
{
    std::string s; 
    int count = 0;
    if (data.SerializeToString(&s)) {
        count = mWebSocketClient->sendBinaryMessage(QByteArray(s.c_str(), s.length()));
    }

    if (s.length() != count) {
        return false;
    }
    return true;
}

void Cloud::reportOnline()
{
    QSharedPointer<SendData> data = QSharedPointer<SendData>(new SendData());
    Ready ready;
    DeviceState* device_state = DeviceState::getInstance();

    QString uuid = QUuid::createUuid().toString().replace(QRegExp("[{}-]"), "");
    QString collect_mode_str = device_state->getCollectModeStr();

    data->set_serianum(uuid.toLatin1().data());
    data->set_type("action");
    data->set_action("ready");
    ready.set_currentmode(collect_mode_str.toLatin1().data());
    ready.set_lon(device_state->getLongitude());
    ready.set_lat(device_state->getLatitude());
    *(data->mutable_ready()) = ready;

    if (serializeSend(*data)) {
        mReplyTrack->addTrack(data);
    }
}

void Cloud::responseCollectCommand(const SendData& received_data)
{
    SendData data;
    data.set_serianum(received_data.serianum());
    data.set_type("reply");
    data.set_action(received_data.action());
    data.set_success("true");
    data.set_message(QString::fromLocal8Bit("成功").toUtf8().data());

    //TODO: 增加 data 字段

    if (serializeSend(data)) {
        ZKGDDEBUG("Response Collect Command");
    }
}
