#ifndef LINUXVIRUS_H
#define LINUXVIRUS_H

#include "virus.h"

class LinuxVirus : public Virus
{
public:
    LinuxVirus(int myId, Computer myComputer);

private:
    int id;
    Computer myComp;
};

#endif // LINUXVIRUS_H
