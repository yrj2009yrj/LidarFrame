#ifndef __CLOUD_H__
#define __CLOUD_H__

#include <QObject>
#include <QSet>

#include "SendData.pb.h"
using namespace com::caspe::devicemanagement::util;

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

    void handleBinaryMessage(const QByteArray& message);

    void responseConnectCheck(const SendData&);

    void reportOnline();

    void serviceAddressChanged();

    int serializeSend(const SendData& data);

private:
    QWebSocket* mWebSocketClient;

    QString mUrl;

    bool mIsConnected;

    int mReconnectionTimer;

    ServiceFind*  mServiceFind;

    QSet<QString> mUuidSet;
};

#endif
