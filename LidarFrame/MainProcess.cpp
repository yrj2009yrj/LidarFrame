#include "MainProcess.h"

#include "BLYCard.h"
#include "Cloud.h"
//#include "ServiceFind.h"

#include "SendData.pb.h"
using namespace com::caspe::devicemanagement::util;

MainProcess::MainProcess(QObject* parent)
{
    mCloud = new Cloud(this);
    mCloud->connectCloud();
    
    setCardDevice();

    //mServiceFind = new ServiceFind(this);
}

MainProcess::~MainProcess()
{
}

void MainProcess::setAngleDevice()
{
}

void MainProcess::setCardDevice()
{
    mCard = new BLYCard(this);

    //TODO É¾³ýnewµÄ×ÊÔ´
}

void MainProcess::setLaserDevice()
{
}
