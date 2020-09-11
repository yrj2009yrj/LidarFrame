#ifndef __MAINPROCESS_H__
#define __MAINPROCESS_H__

#include <QObject>

#include "AngleBase.h"
#include "CardBase.h"
#include "LaserBase.h"

class Cloud;

class MainProcess :public QObject
{
    Q_OBJECT

public:
    MainProcess(QObject* parent = nullptr);
    virtual ~MainProcess();

private:
    void setAngleDevice();
    void setCardDevice();
    void setLaserDevice();

private:
    AngleBase* mAngle;
    CardBase* mCard;
    LaserBase* mLaser;

    Cloud* mCloud;
};

#endif
