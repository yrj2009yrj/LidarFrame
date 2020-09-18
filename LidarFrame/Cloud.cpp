#include "Cloud.h"

#include <QtCore/QTimerEvent>
#include <QtWebSockets/QWebSocket>

#include "ServiceFind.h"

#include "ZkgdLog.h"

Cloud::Cloud(QObject* parent)
    :mIsConnected(false)
    ,mTimerId(0)
    ,mReconnectionTimer(0)
{
    mWebSocketClient = new QWebSocket();
    mWebSocketClient->setParent(this);

    connect(mWebSocketClient, &QWebSocket::connected, this, &Cloud::connected);
    connect(mWebSocketClient, &QWebSocket::disconnected, this, &Cloud::reconnection);

    mServiceFind = new ServiceFind(this);
    connect(mServiceFind, &ServiceFind::serviceAddressChanged, this, &Cloud::serviceAddressChanged);

    mTimerId = startTimer(2000);
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
}

void Cloud::serviceAddressChanged()
{
    mWebSocketClient->abort();
    mWebSocketClient->open(QUrl(mServiceFind->getServiceAddress()));
}

void Cloud::reconnection()
{
    
    if (mIsConnected)
    {
        mReconnectionTimer = startTimer(5000);
    }
}

void Cloud::timerEvent(QTimerEvent* event)
{
    static int index = 0;

    if (mTimerId == event->timerId())
    {
        mWebSocketClient->sendTextMessage("index = " + QString::number(index++));
    }
    else if (mReconnectionTimer == event->timerId())
    {
        qDebug() << "Reconnection Cloud";
        mWebSocketClient->open(QUrl(mServiceFind->getServiceAddress()));
    }
}
