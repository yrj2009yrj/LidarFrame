#ifndef __SERVICEFIND_H__
#define __SERVICEFIND_H__

#include <QObject>

class QUdpSocket;

class ServiceFind :public QObject
{
    Q_OBJECT

public:
    explicit ServiceFind(QObject* parent = nullptr);
    virtual ~ServiceFind();

    QString getServiceAddress();

signals:
    void serviceAddressChanged();

private:
    void udpRecv();

private:
    QUdpSocket* mUdpSocket;

    int mServiceForm;
    QString mPcCloud;
    QString mRealCloud;
};

#endif // __SERVICEFIND_H__
