#include "Cloud.h"

#include <QTimerEvent>
#include <QtWebSockets/QWebSocket>

Cloud::Cloud(QObject* parent)
    :mIsConnected(false)
    ,mTimerId(0)
{
    mWebSocketClient = new QWebSocket();
    mWebSocketClient->setParent(this);

    connect(mWebSocketClient, &QWebSocket::connected, []() {qDebug() << "Connect Cloud Success"; });
    connect(mWebSocketClient, &QWebSocket::disconnected, this, &Cloud::reconnection);

    mTimerId = startTimer(2000);
}

Cloud::~Cloud()
{
}

void Cloud::connectCloud(QString url)
{
    mWebSocketClient->open(QUrl(url));
    mUrl = url;
    mIsConnected = true;
}

void Cloud::disconnectCloud()
{
    qDebug() << "Disconnection Cloud";
    mIsConnected = false;
    mWebSocketClient->close();

}

void Cloud::reconnection()
{
    if (mIsConnected)
    {
        qDebug() << "Reconnection Cloud";
        mWebSocketClient->open(QUrl(mUrl));
    }
}

void Cloud::timerEvent(QTimerEvent* event)
{
    static int index = 0;

    if (mTimerId = event->timerId())
    {
        mWebSocketClient->sendTextMessage("index = " + QString::number(index++));
    }
}
