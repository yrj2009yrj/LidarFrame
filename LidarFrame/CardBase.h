#ifndef __CARDBASE_H__
#define __CARDBASE_H__

#include "PartBase.h"

class CardBase :public PartBase
{
    Q_OBJECT

public:
    CardBase(QObject* parent = nullptr);
    virtual ~CardBase();
};

#endif
