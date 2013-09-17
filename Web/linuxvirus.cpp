#include "linuxvirus.h"
#include "computer.h"
#include "saver.h"


LinuxVirus::LinuxVirus()
{
}

void LinuxVirus::activate(int compId)
{
    myCompId = compId;
    Computer* myComp = Saver::instance()->returnCompById(myCompId);
    int randomCount = qrand() % int(1/probability());
    if (randomCount == int(1/(2*probability()))
            && (myComp->myOS->isLinux())) {
        myComp->infectIt();
       infectAroundLocal();
    }
}

void LinuxVirus::infectAroundLocal()
{
    Computer* myComp = Saver::instance()->returnCompById(myCompId);
    if (!myComp->amIConnectToLocal()) {
        return;
    }
    for (int i = 0; i < myComp->contactList.size(); i++) {
        emit sendToLocal(myComp->contactList[i], this);
    }
}
