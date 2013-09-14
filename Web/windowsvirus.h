#ifndef WINDOWSVIRUS_H
#define WINDOWSVIRUS_H

#include "virus.h"
#include "windowsos.h"

class WindowsVirus : public Virus
{
public:
    WindowsVirus();
    enum {Type = 3};
    int type() const { return Type; }
    static const double probability = 0.01;

    void activate(int compId);
    void infectAroundLocal();
    void sendAcrossLocal(int unluckyCompId);
};

#endif // WINDOWSVIRUS_H
