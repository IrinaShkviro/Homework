#ifndef VIRUS_H
#define VIRUS_H

#include "computer.h"

class Virus
{
public:
    Virus(int myId, Computer myComputer);

protected:
    int id;
    Computer myComp;

private:
    void makeComputerIll();
    void sendAcrossLocal(int virusId, int unluckyCompId);
    void sendAcrossWeb(int virusId, int unluckyCompId);
};

#endif // VIRUS_H
