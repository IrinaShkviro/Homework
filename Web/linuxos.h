#ifndef LINUXOS_H
#define LINUXOS_H

#include "operatingsystem.h"

class LinuxOS : public OperatingSystem
{
public:
    LinuxOS();
    virtual bool isLinux() {return true;}
};

#endif // LINUX_H
