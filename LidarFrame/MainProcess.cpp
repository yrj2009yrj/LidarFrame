#include "MainProcess.h"

#include "BLYCard.h"
#include "Cloud.h"

#include "SendData.pb.h"
using namespace com::caspe::devicemanagement::util;

MainProcess::MainProcess(QObject* parent)
{
    mCloud = new Cloud(this);
    mCloud->connectCloud("ws://192.168.3.21:8899");
    
    setCardDevice();
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
