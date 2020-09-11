#ifndef __BLYCARD_H__
#define __BLYCARD_H__

#include "CardBase.h"

class BLYCard :public CardBase
{
    Q_OBJECT

public:
    BLYCard(QObject* parent = nullptr);
    virtual ~BLYCard();

protected:
    virtual void openPart();
    virtual void initPart();
    virtual void closePart();
};

#endif
