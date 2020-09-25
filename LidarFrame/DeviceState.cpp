#include "DeviceState.h"

#include <QDebug>

DeviceState* DeviceState::instance = DeviceState::getInstance();

DeviceState::DeviceState(QObject* parent) : QObject(parent)
{
    mCollectMode = CollectMode::READY;
    mLongitude = 0;
    mLatitude = 0;
}

DeviceState::~DeviceState()
{
}

DeviceState* DeviceState::getInstance()
{
    static DeviceState instance;
    return &instance;
}

QString DeviceState::getCollectModeStr()
{
    if (mCollectMode == CollectMode::FIXED_POINT) {
        mCollectModeStr = "fixed_point";
    }
    else if (mCollectMode == CollectMode::HORIZONTAL) {
        mCollectModeStr = "horizontal";
    }
    else if (mCollectMode == CollectMode::VERTICAL) {
        mCollectModeStr = "vertical";
    }
    else if (mCollectMode == CollectMode::DRIVING) {
        mCollectModeStr = "driving";
    }
    else if (mCollectMode == CollectMode::CUSTOM) {
        mCollectModeStr = "custom";
    }
    else {
        mCollectModeStr = "ready";
    }
    return mCollectModeStr;
}

float DeviceState::getLongitude()
{
    return mLongitude;
}

void DeviceState::setLongitude(float longitude)
{
    mLongitude = longitude;
}

float DeviceState::getLatitude()
{
    return mLatitude;
}

void DeviceState::setLatitude(float latitude)
{
    mLatitude = latitude;
}

DeviceState::CollectMode DeviceState::getCollectMode()
{
    return mCollectMode;
}

void DeviceState::setCollectMode(CollectMode collect_mode)
{
    mCollectMode = collect_mode;
}
