#ifndef WINDOWSVIRUS_H
#define WINDOWSVIRUS_H

#include "virus.h"
#include "windowsos.h"

/**
 * @brief The WindowsVirus class - describe virus for computers with
 *  Windows operation system
 */
class WindowsVirus : public Virus
{
public:
    /**
     * @brief WindowsVirus  - empty constructor
     */
    WindowsVirus();
    double probability() const { return 1; }

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

#endif // WINDOWSVIRUS_H
