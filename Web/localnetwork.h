#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <QObject>
#include <QGraphicsItem>
#include <QList>
#include "saver.h"
#include "linuxvirus.h"
#include "windowsvirus.h"
#include "linuxos.h"
#include "windowsos.h"

class LocalNetwork: public QObject
{
    Q_OBJECT
public:
    LocalNetwork(int compsCount);

private:
    int currentId;
    int compsCount;
    QList<Virus*> virusList;
    void send(int getterId, Program* sendingProgram);
    void connectSignalsFromComps();
    void sendProgram(int compId, Program* message);
    void addComputerInNetwork(OperatingSystem* os, int newCompId);
    void createNetwork();
    void createVirus();
};

#endif // LocalNetwork_H
