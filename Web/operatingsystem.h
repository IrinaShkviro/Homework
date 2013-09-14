#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H

class OperatingSystem
{
public:
    enum {Type = 13};
    int type() const { return Type; }
    static const int virusProbability;
};

#endif // OPERATINGSYSTEM_H
