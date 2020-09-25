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
    virtual void open() = 0;
    virtual void init() = 0;
    virtual void close() = 0;

protected:
    QString mName;
};

#endif
