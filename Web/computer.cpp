#include "computer.h"

Computer::Computer(int myId):
    isIll(false)
  , id(myId)
  , isConnectToWeb(false)
  , isConnectToLocal(true)
{
}

bool Computer::amIIll()
{
    return isIll;
}

bool Computer::amIConnectToLocal()
{
    return isConnectToLocal;
}

bool Computer::amIConnectToWeb()
{
    return isConnectToWeb;
}

int Computer::myId()
{
    return id;
}

void Computer::connectToWeb()
{
    isConnectToWeb = true;
}

void Computer::disconnectToWeb()
{
    isConnectToWeb = false;
}

void Computer::connectToLocal()
{
    isConnectToLocal = true;
}

void Computer::disconnectToLocal()
{
    isConnectToLocal = false;
}
