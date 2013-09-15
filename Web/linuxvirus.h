#ifndef LINUXVIRUS_H
#define LINUXVIRUS_H

#include "virus.h"
#include "linuxos.h"

class LinuxVirus : public Virus
{
public:
    LinuxVirus();
    double probability() const { return 1;}

    void activate(int compId);
    void infectAroundLocal();
     void sendAcrossLocal(int unluckyCompId);
};

#endif // LINUXVIRUS_H
