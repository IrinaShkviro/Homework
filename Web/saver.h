#ifndef SAVER_H
#define SAVER_H

#include <QMap>
#include "computer.h"

class Saver
{
public:
    Saver();
    static Saver* instance();
     Computer* returnCompById(int id);
     void addComputer(Computer* comp);
     QList<Computer*> myCompList() const;

private:
     QMap<int, Computer*>* computers;
};

#endif // SAVER_H
