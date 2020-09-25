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

inline QTextStream& operator<<(QTextStream& stream, const std::string& str)
{
    stream << QString::fromStdString(str);
    return stream;
}

#define ZKGDASSERT(...)   do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDERROR(...)    do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDWARN(...)     do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDINFO(...)     do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDDEBUG(...)    do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDVERBOSE(...)  do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)
#define ZKGDRAW(...)      do{QString __str;QTextStream __stream(&__str);__stream<<__VA_ARGS__;qDebug()<<__str;}while(0)

#define ZKGDQDEBUG(...)   do{qDebug()<<__VA_ARGS__;}while(0)

#endif // __ZKGDLOG_H__
