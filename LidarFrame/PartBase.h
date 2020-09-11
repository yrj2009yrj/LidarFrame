#ifndef __PARTBASE_H__
#define __PARTBASE_H__

#include <QObject>

class PartBase : public QObject
{
    Q_OBJECT

public:
    PartBase(QObject* parent = nullptr);
    virtual ~PartBase();

protected:
    virtual void openPart() = 0;
    virtual void initPart() = 0;
    virtual void closePart() = 0;

protected:
    QString mName;
};

#endif
