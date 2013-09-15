#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "operatingsystem.h"

class Program: public QObject
{
    Q_OBJECT
public:
     void activate(int compId);
     virtual bool isVirus() { return false;}

signals:
    void sendToLocal(int compId, Program* message);

protected:
    OperatingSystem* myOS;
    int myCompId;
    void sendAcrossLocal(int compId, Program *message);
};

#endif // PROGRAM_H
