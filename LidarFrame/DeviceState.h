#ifndef __DEVICESTATE_H__
#define __DEVICESTATE_H__

#include <QObject>

class DeviceState : public QObject
{
    Q_OBJECT

public:
    enum class CollectMode
    {
        FIXED_POINT,
        HORIZONTAL,
        VERTICAL,
        DRIVING,
        CUSTOM,
        READY,
    };

public:
    ~DeviceState();
    DeviceState(const DeviceState&) = delete;
    DeviceState& operator=(const DeviceState&) = delete;

    static DeviceState* getInstance();

    QString getCollectModeStr();
 
    float getLongitude();
    void setLongitude(float longitude);
    float getLatitude();
    void setLatitude(float latitude);
    CollectMode getCollectMode();
    void setCollectMode(CollectMode collect_mode);

signals:

public:

private:
    DeviceState(QObject* parent = nullptr);
    static DeviceState* instance;

    CollectMode mCollectMode;
    QString mCollectModeStr;
    float mLongitude;
    float mLatitude;
};

#endif // __DEVICESTATE_H__

