#include "localnetwork.h"

LocalNetwork::LocalNetwork(int compsCount):
    currentId(0)
  , compsCount(compsCount)
{
    connectSignalsFromComps();
}

void LocalNetwork::connectSignalsFromComps()
{
    foreach (Computer* const comp, Saver::instance()->myCompList()) {
        connect(comp, SIGNAL(sendToLocal(int,Program*)), this, SLOT(send(int, Program)));
    }
}

void LocalNetwork::send(int getterId, Program *sendingProgram)
{
    if (Saver::instance()->myCompList().isEmpty()) {
        return;
    }
    if (!Saver::instance()->myCompList().contains(Saver::instance()->returnCompById(getterId))) {
        return;
    }
    Saver::instance()->returnCompById(getterId)->getFromLocalNetwork(sendingProgram);
}

void LocalNetwork::addComputerInNetwork(OperatingSystem *os, int newCompId)
{
    Saver::instance()->addComputer(os, newCompId);
}

void LocalNetwork::createNetwork()
{
    OperatingSystem* os;
    for (int i = 0; i < compsCount; i++) {
        if (i % 2 == 0) {
            os = new LinuxOS();
        }
        else {
            os = new WindowsOS();
        }
        addComputerInNetwork(os, i);
    }
}

void LocalNetwork::createVirus()
{    
    int randomCount = qrand();
    if (randomCount % 2 == 0) {
        virusList.append(new LinuxVirus());
    }
    else {
        virusList.append(new WindowsVirus());
    }
}
