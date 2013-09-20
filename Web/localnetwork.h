#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <QObject>
#include <QString>
#include <QGraphicsItem>
#include <QList>
#include <QQueue>
#include "saver.h"
#include "linuxvirus.h"
#include "windowsvirus.h"
#include "linuxos.h"
#include "windowsos.h"
#include "data.h"

/**
 * @brief The LocalNetwork class - generate some network with computers
 *  and links between them
 */
class LocalNetwork: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief LocalNetwork - create network with computers whih
     *  described in data file
     */
    LocalNetwork();

    /**
     * @brief The myMap struct - consist from computer id and
     *  program which will be set on it
     */
    struct myMap {
        int compId;
        Program* program;
        myMap(int id, Program* proga) {
            compId = id;
            program = proga;
        }
    };

    /**
     * @brief update - check changes in count of computers
     */
    void update();

public slots:
    /**
     * @brief sendToQueue - send program in queue for sending
     * @param getterId - id of computer on which program will be set
     * @param sendingProgram - program which will be set
     */
    void sendToQueue(int getterId, Program* sendingProgram);

    /**
     * @brief addInfectedComp - says about just infected computer
     * @param compId - id of just infected computer
     */
    void addInfectedComp(int compId);

    /**
     * @brief tryToSendProgram - send first program in queue
     */
    void tryToSendProgram();

    /**
     * @brief pushVirusInRandomComp - select random computer and
     *  send virus for it in queue
     */
    void pushVirusInRandomComp();

signals:
    /**
     * @brief noStartData - if we don't have any start data
     */
    void noStartData();

    /**
     * @brief compsCountChanged - if count of comps was changed
     * @param newCompsCount - count of comps
     */
    void compsCountChanged(int newCompsCount);

    /**
     * @brief infectedCompsCountChanged - if new comp was infected
     * @param justInfectedCompId - id of just infected computer
     */
    void infectedCompsCountChanged(int justInfectedCompId);

    /**
     * @brief success - says whether some actions that user want to do were done
     * @param isSuccess
     */
    void success(bool isSuccess);

    /**
     * @brief triedToInfect - id of computer which virus tried to infect
     */
    void triedToInfect(int);

private:
    int infectedCompsCount;
    int compsCount;
    int step;
    const int compsToInfectId[8] = {1, 2, 4, 3, 5, 4, 2, 1};
    QQueue<myMap>* expectForDownload;

    /**
     * @brief changeCompsCount - change count of comps in network
     * @param count - new count of comps
     */
    void changeCompsCount(int count);

    /**
     * @brief send - send sendingProgram to computer with getterId
     * @param getterId
     * @param sendingProgram
     */
    void send(int getterId, Program* sendingProgram);

    /**
     * @brief addComputerInNetwork - add comp with operation system os and
     *  id newCompId in this network
     * @param os
     * @param newCompId
     */
    void addComputerInNetwork(OperatingSystem* os, int newCompId);

    /**
     * @brief createNetwork - create this network with start data
     */
    void createNetwork();

    /**
     * @brief createVirus
     * @return new example of virus with random operation system
     */
    Virus* createVirus();

    /**
     * @brief getLinksBetweenComps - get information about links between computers
     *  from file with data
     * @param startData - start data from file
     */
    void getLinksBetweenComps(QList<QString> startData);

    /**
     * @brief startDownload - send 1 program in queue to specified adress
     * @return
     */
    bool startDownload();
};

#endif // LocalNetwork_H
