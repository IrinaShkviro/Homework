#ifndef NETWORK_H
#define NETWORK_H

#include <QList>

class Network
{
public:
    Network();

private:
    QList<int> connectedCompId;
    void send(int sendingId, int getterId);
};

#endif // NETWORK_H
