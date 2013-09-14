#include "localnetwork.h"

LocalNetwork::LocalNetwork():
    compsCount(0)
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

void LocalNetwork::getLinksBetweenComps(QList<QString> startData)
{
    foreach (Computer* const comp, Saver::instance()->myCompList()) {
        QList<int> connectedCompsNumbers;
        QStringList numbersInString = startData[0].split(",");
        while (!numbersInString.isEmpty()) {
            connectedCompsNumbers.append(numbersInString[0].toInt());
            numbersInString.removeAt(0);
        }
        comp->addContactList(connectedCompsNumbers);
    }
}

void LocalNetwork::createNetwork()
{
    Data firstData;
    QList<QString> startData = firstData.getStartData();
    compsCount = startData[0].toInt();
    startData.removeAt(0);
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
    getLinksBetweenComps(startData);
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
