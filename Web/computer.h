#ifndef COMPUTER_H
#define COMPUTER_H

#include <QList>

class Computer
{
public:
    Computer(int myId);
    bool amIIll();
    int myId();
    bool amIConnectToWeb();
    bool amIConnectToLocal();

protected:
    QList<int> contactList;

private:
    bool isIll;
    int id;
    bool isConnectToWeb;
    bool isConnectToLocal;
    void connectToWeb();
    void disconnectToWeb();
    void connectToLocal();
    void disconnectToLocal();
    void sendAcrossLocal(int sendingId, int getterId);
    void getFromNetwork(int sendingId);
    void sendAcrossWeb(int sendingId, int getterId);
};

#endif // COMPUTER_H
