#include "windowsvirus.h"
#include "computer.h"
#include "saver.h"


WindowsVirus::WindowsVirus()
{
}

void WindowsVirus::sendAcrossLocal(int unluckyCompId)
{
      emit sendToLocal(unluckyCompId, this);
}

void WindowsVirus::activate(int compId)
{
    myCompId = compId;
    Computer* myComp = Saver::instance()->returnCompById(myCompId);
    int randomCount = qrand() % int(1/probability());
    if (randomCount == int(1/(2*probability()))
            && myComp->myOS->type() == WindowsOS::Type) {
        myComp->infectIt();
        infectAroundLocal();
    }
}

void WindowsVirus::infectAroundLocal()
{
    Computer* myComp = Saver::instance()->returnCompById(myCompId);
    if (!myComp->amIConnectToLocal()) {
        return;
    }
    for (int i = 0; i < myComp->contactList.size(); i++) {
        sendAcrossLocal(myComp->contactList[i]);
    }
}
