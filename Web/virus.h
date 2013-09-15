#ifndef VIRUS_H
#define VIRUS_H

#include "qmath.h"
#include "program.h"

class Virus: public Program
{

public:
    enum {Type = 1};
    int type() const { return Type; }
    virtual double probability() const = 0;
    virtual void activate(int compId) = 0;
    virtual bool isVirus() {return true;}
     void infectAroundLocal();

protected:
     void sendAcrossLocal(int unluckyCompId);
};

#endif // VIRUS_H
