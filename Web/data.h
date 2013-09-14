#ifndef DATA_H
#define DATA_H

#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

class Data
{
public:
    Data();
    QList<QString> getStartData();

private:
    QList<QString> startLines;
    void readFile();
};

#endif // DATA_H
