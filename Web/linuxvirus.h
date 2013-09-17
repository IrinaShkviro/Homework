#ifndef LINUXVIRUS_H
#define LINUXVIRUS_H

#include "virus.h"
#include "linuxos.h"

/**
 * @brief The LinuxVirus class - describe virus for computers with
 *  Linux operation system
 */
class LinuxVirus : public Virus
{
public:
    /**
     * @brief LinuxVirus - empty constructor
     */
    LinuxVirus();

    /**
     * @brief probability
     * @return probability with which computer will be infected
     */
    double probability() const { return 1;}

    /**
     * @brief activate - infect virus with id compId
     * @param compId - id of computer which will be infected
     */
    void activate(int compId);

    /**
     * @brief infectAroundLocal - tries to infected all computers connected with this
     */
    void infectAroundLocal();
};

#endif // LINUXVIRUS_H
