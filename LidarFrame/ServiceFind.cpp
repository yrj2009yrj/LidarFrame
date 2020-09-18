#include "ServiceFind.h"

#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkDatagram>

#include "ZkgdLog.h"

ServiceFind::ServiceFind(QObject* parent)
{
    mUdpSocket = new QUdpSocket(this);
    mUdpSocket->bind(60000, QUdpSocket::ShareAddress);
    connect(mUdpSocket, &QUdpSocket::readyRead, this, &ServiceFind::udpRecv);

    //TODO: 从其他地方获取设备的实际地址
    mRealCloud = "ws://192.168.3.21:8899";
    mServiceForm = 0;
}

ServiceFind::~ServiceFind()
{
}

void ServiceFind::udpRecv()
{
    QByteArray recv_data = mUdpSocket->receiveDatagram().data();

    if (recv_data.startsWith("PcCloudService-")) {
        mPcCloud = recv_data.mid(15);
        QString pc_cloud_ip = mPcCloud.mid(5).split(":")[0];
        //ZKGDDEBUG("Pc Cloud Ip: " << pc_cloud_ip);

        //TODO: 修改为设备实际的序列号和IP地址
        mUdpSocket->writeDatagram(QByteArray("9") + ":" + QByteArray("192.168.3.22"), QHostAddress(pc_cloud_ip), 60001);
    }
    else if (recv_data.startsWith("ConnectToRealCloud-")) {
        mServiceForm = 0;
        emit serviceAddressChanged();
        //ZKGDDEBUG("Connect To Real Cloud: " << "---X---X---");
    }
    else if (recv_data.startsWith("ConnectToPcCloud-")) {
        mServiceForm = 1;
        emit serviceAddressChanged();
        //ZKGDDEBUG("Connect To Pc Cloud: " << mPcCloud);
    }
}

QString ServiceFind::getServiceAddress()
{
    if (mServiceForm == 1)
    {
        return mPcCloud;
    }
    return mRealCloud;
}