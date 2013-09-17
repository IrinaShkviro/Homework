#ifndef LINUXOS_H
#define LINUXOS_H

#include "operatingsystem.h"

/**
 * @brief The LinuxOS class - class which describe Linux operation system
 */
class LinuxOS : public OperatingSystem
{
public:
    /**
     * @brief LinuxOS - empty constructor
     */
    LinuxOS();

    /**
     * @brief isLinux
     * @return true if operation system is Linux
     */
    virtual bool isLinux() {return true;}
};

#endif // LINUX_H
