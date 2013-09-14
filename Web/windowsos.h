#ifndef WINDOWSOS_H
#define WINDOWSOS_H

#include "operatingsystem.h"

class WindowsOS : public OperatingSystem
{
public:
    WindowsOS();
    enum {Type = 11};
    int type() const { return Type; }
    static const int virusProbability = 0.02;
};

#endif // WINDOWS_H
