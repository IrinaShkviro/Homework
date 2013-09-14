#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QList>
#include "program.h"
#include "linuxos.h"
#include "windowsos.h"
#include "windowsvirus.h"
#include "linuxvirus.h"

class Computer: public QObject
{
    Q_OBJECT
public:
    Computer();
    Computer(OperatingSystem* myOS, int id);
    QList<int> contactList;
    QList<Program*> programList;
    OperatingSystem* myOS;
    bool amIIll();
    bool amIConnectToLocal();
    void getFromLocalNetwork(Program* program);
    void infectIt();

public slots:
    void fromProgramToLocal(int compId, Program* message);

signals:
    void sendToLocal(int compId, Program* message);

private:
    int myId;
    int infectProbability;
    bool isIll;
    bool isConnectToLocal;
    Virus* myVirus;
    void connectToLocal();
    void disconnectToLocal();
    void sendAcrossLocal(Program* message, int getterId);
    void connectProgramsSignalsWithMySlots();
    void setProgram(Program* programForSet);
    void setOS(OperatingSystem* os);
    void activateVirus();
    void infectAroundLocal();
};

#endif // COMPUTER_H
