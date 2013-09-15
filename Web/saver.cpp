#include "saver.h"


Saver::Saver():
    computers(new QMap<int, Computer*>())
{
}

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

void Saver::addComputer(Computer *comp)
{
    instance()->computers->insert(comp->returnId(), comp);
}

QList<Computer*> Saver::myCompList() const
{
    if (!instance()->computers) {
        return QList<Computer*>();
    }
    return instance()->computers->values();
}
