#ifndef WINDOWSOS_H
#define WINDOWSOS_H

#include "operatingsystem.h"

/**
 * @brief The WindowsOS class  - class which describe Windows operation system
 */
class WindowsOS : public OperatingSystem
{
public:
    /**
     * @brief WindowsOS - empty constructor
     */
    WindowsOS();

    /**
     * @brief isWindows
     * @return true if operation system is Windows
     */
    virtual bool isWindows() {return true;}
};

#endif // WINDOWS_H
