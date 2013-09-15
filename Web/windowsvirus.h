#ifndef WINDOWSVIRUS_H
#define WINDOWSVIRUS_H

#include "virus.h"
#include "windowsos.h"

class WindowsVirus : public Virus
{
public:
    WindowsVirus();
    double probability() const { return 1; }

    void activate(int compId);
    void infectAroundLocal();
    void sendAcrossLocal(int unluckyCompId);
};

#endif // WINDOWSVIRUS_H
