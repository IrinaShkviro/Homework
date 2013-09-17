#include "computer.h"


Computer::Computer()
{
}

Computer::Computer(OperatingSystem *myOS, int id):
    isIll(false)
  , isConnectToLocal(true)
  , myId(id)
  , infectProbability(0)
  , myOS(myOS)
{
}

int Computer::returnId()
{
    return myId;
}

void Computer::addContactList(QList<int> contactNumbers)
{
    contactList = contactNumbers;
}

bool Computer::amIIll()
{
    return isIll;
}

bool Computer::amIConnectToLocal()
{
    return isConnectToLocal;
}

void Computer::infectIt()
{
    if (isIll) {
        return;
    }
    isIll = true;
    emit iWasInfected(myId);
}

void Computer::connectToLocal()
{
    isConnectToLocal = true;
}

void Computer::disconnectToLocal()
{
    isConnectToLocal = false;
}

void Computer::setProgram(Program *programForSet)
{
    programList.append(programForSet);
    connect(programForSet, SIGNAL(sendToLocal(int, Program*)), this, SLOT(fromProgramToLocal(int,Program)));
    if (programForSet->isVirus()) {
        myVirus = static_cast<Virus*>(programForSet);
        if (myVirus != NULL) {
            infectProbability = myVirus->probability();
            myVirus->activate(myId);
        }
    }
    emit triedToInfect(myId);
}

void Computer::getFromLocalNetwork(Program *program)
{
    setProgram(program);
}

void Computer::fromProgramToLocal(int compId, Program *message)
{
    emit sendToLocal(compId, message);
}

