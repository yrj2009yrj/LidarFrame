#ifndef __LASERBASE_H__
#define __LASERBASE_H__

#include "PartBase.h"

class LaserBase :public PartBase
{
    Q_OBJECT

public:
    LaserBase(QObject* parent = nullptr);
    virtual ~LaserBase();
};

#endif
