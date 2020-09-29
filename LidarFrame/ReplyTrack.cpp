#include "ReplyTrack.h"

#include <QTimerEvent>

#include "ZkgdLog.h"

ReplyTrack::ReplyTrack(QObject* parent)
    : QObject(parent)
{
}

ReplyTrack::~ReplyTrack()
{
}

void ReplyTrack::addTrack(QSharedPointer<SendData> data)
{
    QString uuid = QString::fromStdString(data->serianum());
    int timer_id = startTimer(5000);
    mTimer.insert(uuid, timer_id);
    mReply.insert(timer_id, data);
}

void ReplyTrack::removeTrack(QString uuid)
{
    int timer_id = mTimer[uuid];
    killTimer(timer_id);
    mTimer.remove(uuid);
    mReply.remove(timer_id);
}

void ReplyTrack::timerEvent(QTimerEvent* event)
{
    int timer_id = event->timerId();
    ZKGDDEBUG("There are unresponsive sequences: " << mReply[timer_id]->serianum());
}
