#ifndef __ANGLEBASE_H__
#define __ANGLEBASE_H__

#include "PartBase.h"

class AngleBase :public PartBase
{
    Q_OBJECT

public:
    AngleBase(QObject* parent = nullptr);
    virtual ~AngleBase();

protected:
    virtual QString getCollectMode() = 0;
    virtual float getLon() = 0;
    virtual float getLat() = 0;

private:
    QString mCollectMode;
    float lon;
    float lat;
};

#endif
