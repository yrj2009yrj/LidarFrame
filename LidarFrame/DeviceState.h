#ifndef __DEVICESTATE_H__
#define __DEVICESTATE_H__

#include <QObject>

class DeviceState : public QObject
{
    Q_OBJECT

public:
    ~DeviceState();
    DeviceState(const DeviceState&) = delete;
    DeviceState& operator=(const DeviceState&) = delete;

    static DeviceState* getInstance();

signals:

public:

private:
    DeviceState(QObject* parent = nullptr);
    static DeviceState* instance;
};

#endif // __DEVICESTATE_H__

