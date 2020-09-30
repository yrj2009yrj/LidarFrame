#ifndef __CLOUD_H__
#define __CLOUD_H__

#include <QObject>

#include "SendData.pb.h"
using namespace com::caspe::devicemanagement::util;

class QWebSocket;

class ReplyTrack;
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

    void responseCollectCommand(const SendData& received_data);

    void reportOnline();

    void serviceAddressChanged();

    bool serializeSend(const SendData& data);

private:
    QWebSocket* mWebSocketClient;

    QString mUrl;

    bool mIsConnected;

    int mReconnectionTimer;

    ServiceFind* mServiceFind;

    ReplyTrack* mReplyTrack;    //监测发送给服务端后，是否有对应的回复
};

#endif
