#ifndef __CLOUD_H__
#define __CLOUD_H__

#include <QObject>

class QWebSocket;

class ServiceFind;

class Cloud :public QObject
{
    Q_OBJECT

public:
    Cloud(QObject* parent = nullptr);
    virtual ~Cloud();

    void connectCloud();
    void disconnectCloud();

protected:
    void timerEvent(QTimerEvent* event) override;

private:
    void reconnection();

    void connected();

    void serviceAddressChanged();

private:
    QWebSocket* mWebSocketClient;

    QString mUrl;
    bool mIsConnected;

    int mTimerId;

    int mReconnectionTimer;

    ServiceFind*  mServiceFind;
};

#endif
