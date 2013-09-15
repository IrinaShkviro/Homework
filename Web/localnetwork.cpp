#include "localnetwork.h"

LocalNetwork::LocalNetwork():
    compsCount(0)
  , infectedCompsCount(0)
  , expectForDownload(new QQueue<myMap>())
{
    createNetwork();
}

void LocalNetwork::update()
{
    emit compsCountChanged(compsCount);
}

void LocalNetwork::sendToQueue(int getterId, Program *sendingProgram)
{
    expectForDownload->append(myMap(getterId, sendingProgram));
}

bool LocalNetwork::startDownload()
{
    if (expectForDownload->isEmpty()) {
        return false;
    }
    myMap currentDownload = expectForDownload->takeAt(0);
    send(currentDownload.compId, currentDownload.program);
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

void LocalNetwork::addInfectedComp(int compId)
{
    emit infectedCompsCountChanged(compId);
}

void LocalNetwork::tryToSendProgram()
{
    if (!expectForDownload) {
        return;
    }
    if (expectForDownload->isEmpty()) {
        return;
    }
    myMap progaramToSend = expectForDownload->takeFirst();
    send(progaramToSend.compId, progaramToSend.program);
}

void LocalNetwork::addComputerInNetwork(OperatingSystem *os, int newCompId)
{
    Computer* newComp = new Computer(os, newCompId);
    connect(newComp, SIGNAL(sendToLocal(int,Program*)), this, SLOT(sendToQueue(int,Program*)));
    connect(newComp, SIGNAL(iWasInfected(int)), this, SLOT(addInfectedComp(int)));
    Saver::instance()->addComputer(newComp);
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

void LocalNetwork::changeCompsCount(int count)
{
    compsCount = count;
    emit compsCountChanged(compsCount);
}

void LocalNetwork::createNetwork()
{
    Data firstData;
    QList<QString> startData = firstData.getStartData();
    if (startData.isEmpty()) {
        emit noStartData();
        return;
    }
    changeCompsCount(startData[0].toInt());
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

Virus *LocalNetwork::createVirus()
{    
    int randomCount = qrand();
    if (randomCount % 2 == 0) {
        return new LinuxVirus();
    }
    else {
        return new WindowsVirus();
    }
}

void LocalNetwork::pushVirusInRandomComp()
{
    if (compsCount == 0) {
        return;
    }
    int randomComp =  qrand() % (compsCount - 1) - 1;
    Virus* virusForRandomComp = createVirus();
    myMap newCouple(randomComp, virusForRandomComp);
    expectForDownload->append(newCouple);
}
