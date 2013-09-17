#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QList>
#include "program.h"
#include "linuxos.h"
#include "windowsos.h"
#include "windowsvirus.h"
#include "linuxvirus.h"

/**
 * @brief The Computer class which connect to network and can get virus
 */
class Computer: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief standart constructor
     */
    Computer();

    /**
     * @brief Computer
     * @param myOS - OperatingSystem
     * @param id - id of computer in network
     */
    Computer(OperatingSystem* myOS, int id);

    /**
     * @brief contactList - list of computers which are connected with this
     */
    QList<int> contactList;

    /**
     * @brief programList - programs that set on this computer
     */
    QList<Program*> programList;

    /**
     * @brief myOS - operation system
     */
    OperatingSystem* myOS;

    /**
     * @brief returnId
     * @return id of this computer
     */
    int returnId();

    /**
     * @brief amIIll
     * @return is computer has virus
     */
    bool amIIll();

    /**
     * @brief amIConnectToLocal
     * @return is computer connect to local network
     */
    bool amIConnectToLocal();

    /**
     * @brief getFromLocalNetwork - get program from local network
     * @param program - it would be set
     */
    void getFromLocalNetwork(Program* program);

    /**
     * @brief infectIt - set virus on computer
     */
    void infectIt();

    /**
     * @brief addContactList - say to computer about connected computers
     * @param contactNumbers - list of computers which connected with this
     */
    void addContactList(QList<int> contactNumbers);

public slots:
    /**
     * @brief fromProgramToLocal - program says to computer to send it to local
     * @param compId - id of computer to whether program will be send
     * @param message - program that would be send to local network
     */
    void fromProgramToLocal(int compId, Program* message);

signals:
    /**
     * @brief sendToLocal - send program from computer to local network
     * @param compId - id of computer to whether program will be send
     * @param message - program that would be send to local network
     */
    void sendToLocal(int compId, Program* message);

    /**
     * @brief iWasInfected - sends to local network to say that virus was set
     * @param id - id of this comp
     */
    void iWasInfected(int id);

    /**
     * @brief triedToInfect - sends to local network to say that virus was tried to set
     * @param id - id of this comp
     */
    void triedToInfect(int id);

private:
    int myId;
    int infectProbability;
    bool isIll;
    bool isConnectToLocal;
    Virus* myVirus;

    /**
     * @brief connectToLocal - connect computer to local network
     */
    void connectToLocal();

    /**
     * @brief disconnectToLocal - disconnect computer to local network
     */
    void disconnectToLocal();
    /**
     * @brief setProgram - sets program on  this computer
     * @param programForSet - program that must be set
     */
    void setProgram(Program* programForSet);
};

#endif // COMPUTER_H
