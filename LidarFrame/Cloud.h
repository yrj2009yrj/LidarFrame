#ifndef __CLOUD_H__
#define __CLOUD_H__

#include <QObject>

class QWebSocket;

class Cloud :public QObject
{
    Q_OBJECT

public:
    Cloud(QObject* parent = nullptr);
    virtual ~Cloud();

    void connectCloud(QString url);
    void disconnectCloud();

protected:
    void timerEvent(QTimerEvent* event) override;

private:
    void reconnection();

private:
    QWebSocket* mWebSocketClient;

    QString mUrl;
    bool mIsConnected;

    int mTimerId;
};

#endif
