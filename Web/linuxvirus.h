#ifndef LINUXVIRUS_H
#define LINUXVIRUS_H

#include "virus.h"
#include "linuxos.h"

class LinuxVirus : public Virus
{
public:
    LinuxVirus();
    enum {Type = 2};
    int type() const { return Type; }
    double probability() const { return 0.01;}

    void activate(int compId);
    void infectAroundLocal();
     void sendAcrossLocal(int unluckyCompId);
};

#endif // LINUXVIRUS_H
