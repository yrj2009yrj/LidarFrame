#ifndef __ZKGDLOG_H__
#define __ZKGDLOG_H__

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>

inline QTextStream &operator<<(QTextStream& stream, const QJsonObject& json_object)
{
    stream << QJsonDocument(json_object).toJson(QJsonDocument::Compact);
    return stream;
}

inline QTextStream &operator<<(QTextStream& stream, const QJsonArray& json_array)
{
    stream << QJsonDocument(json_array).toJson(QJsonDocument::Compact);
    return stream;
}

#define ZKGDASSERT(...)   do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDERROR(...)    do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDWARN(...)     do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDINFO(...)     do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDDEBUG(...)    do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDVERBOSE(...)  do{qDebug()<<__VA_ARGS__;}while(0)
#define ZKGDRAW(...)      do{qDebug()<<__VA_ARGS__;}while(0)

#define ZKGDQDEBUG(...)   do{qDebug()<<__VA_ARGS__;}while(0)

#endif // __ZKGDLOG_H__
