#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "operatingsystem.h"

class Program: public QObject
{
    Q_OBJECT
public:
    enum {Type = 5};
    int type() const { return Type; }
     void activate(int compId);

signals:
    void sendToLocal(int compId, Program* message);

protected:
    OperatingSystem* myOS;
    int myCompId;
    void sendAcrossLocal(int compId, Program *message);
};

#endif // PROGRAM_H
