#ifndef WINDOWSOS_H
#define WINDOWSOS_H

#include "operatingsystem.h"

class WindowsOS : public OperatingSystem
{
public:
    WindowsOS();
    virtual bool isWindows() {return true;}
};

#endif // WINDOWS_H
