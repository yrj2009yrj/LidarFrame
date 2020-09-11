#ifndef __ANGLEBASE_H__
#define __ANGLEBASE_H__

#include "PartBase.h"

class AngleBase :public PartBase
{
    Q_OBJECT

public:
    AngleBase(QObject* parent = nullptr);
    virtual ~AngleBase();
};

#endif
