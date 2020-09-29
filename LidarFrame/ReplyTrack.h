#ifndef __REPLYTRACK_H__
#define __REPLYTRACK_H__

#include <QMap>
#include <QObject>
#include <QSharedPointer>

#include "SendData.pb.h"
using namespace com::caspe::devicemanagement::util;

class QTimerEvent;

class ReplyTrack : public QObject
{
    Q_OBJECT

public:
    ReplyTrack(QObject* parent = nullptr);
    ~ReplyTrack();

    void addTrack(QSharedPointer<SendData> data);
    void removeTrack(QString uuid);

protected:
    virtual void timerEvent(QTimerEvent* event);

private:
    QMap<QString, int> mTimer;
    QMap<int, QSharedPointer<SendData>> mReply;
};

#endif
