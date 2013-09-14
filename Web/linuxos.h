#ifndef LINUXOS_H
#define LINUXOS_H

#include "operatingsystem.h"

class LinuxOS : public OperatingSystem
{
public:
    LinuxOS();
    enum {Type = 10};
    int type() const { return Type; }
    static const int virusProbabilty = 0.01;
};

#endif // LINUX_H
