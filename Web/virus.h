#ifndef VIRUS_H
#define VIRUS_H

#include "qmath.h"
#include "program.h"

/**
 * @brief The Virus class - interface for bad programmes
 */
class Virus: public Program
{

public:
    virtual double probability() const = 0;
    virtual void activate(int compId) = 0;
    virtual bool isVirus() {return true;}

    /**
      * @brief infectAroundLocal - try to infect all computers
      * which connected with comp with this virus
      */
     void infectAroundLocal();
};

#endif // VIRUS_H
