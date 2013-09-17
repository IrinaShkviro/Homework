#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include "operatingsystem.h"

/**
 * @brief The Program class - describes program which can be set on computer
 */
class Program: public QObject
{
    Q_OBJECT
public:
    /**
      * @brief activate - start program on computer with id = compId
      * @param compId
      */
     void activate(int compId);

     /**
      * @brief isVirus
      * @return true if this program is virus
      */
     virtual bool isVirus() { return false;}

signals:
     /**
     * @brief sendToLocal - send this program message to computer with compId
     * @param compId
     * @param message
     */
    void sendToLocal(int compId, Program* message);

protected:
    OperatingSystem* myOS;
    int myCompId;
};

#endif // PROGRAM_H
