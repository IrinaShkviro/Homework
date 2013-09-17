#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

/**
 * @brief The OperatingSystem class - interface for operation system
 */
class OperatingSystem
{
public:
    virtual bool isLinux() {return false;}
    virtual bool isWindows() {return false;}
    static const int virusProbability;
};

#endif // OPERATINGSYSTEM_H
