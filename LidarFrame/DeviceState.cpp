#include "DeviceState.h"

#include <QDebug>

DeviceState* DeviceState::instance = DeviceState::getInstance();

DeviceState::DeviceState(QObject* parent) : QObject(parent)
{
    //mCollectMode = "fixed_point";//fixed_point   horizontal   vertical   driving   custom
    //float lon = ;
    //float lat;
}

DeviceState::~DeviceState()
{
}

DeviceState* DeviceState::getInstance()
{
    static DeviceState instance;
    return &instance;
}
