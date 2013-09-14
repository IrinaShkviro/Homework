#include "saver.h"

Saver *Saver::instance()
{
    static Saver* thisSaver;
    if (!thisSaver) {
        thisSaver = new Saver();
    }
    return thisSaver;
}

Computer *Saver::returnCompById(int id)
{
    return instance()->computers->value(id);
}

void Saver::addComputer(OperatingSystem* os, int newCompId)
{
    instance()->computers->insert(++currentId, new Computer(os, newCompId));
}

QList<Computer*> Saver::myCompList() const
{
    return instance()->computers->values();
}
