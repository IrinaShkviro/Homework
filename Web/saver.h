#ifndef SAVER_H
#define SAVER_H

#include <QMap>
#include "computer.h"

class Saver
{
public:
    static Saver* instance();
     Computer* returnCompById(int id);
     void addComputer(OperatingSystem* os, int newCompId);
     QList<Computer*> myCompList() const;

private:
 //   static Saver* thisSaver;
     QMap<int, Computer*>* computers;
     int currentId;
};

#endif // SAVER_H
