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

class LocalNetwork: public QObject
{
    Q_OBJECT
public:
    LocalNetwork();
    struct myMap {
        int compId;
        Program* program;
        myMap(int id, Program* proga) {
            compId = id;
            program = proga;
        }
    };
    void update();

public slots:
    void sendToQueue(int getterId, Program* sendingProgram);
    void addInfectedComp(int compId);
    void tryToSendProgram();
    void pushVirusInRandomComp();

signals:
    void noStartData();
    void compsCountChanged(int newCompsCount);
    void infectedCompsCountChanged(int justInfectedCompId);

private:
    int infectedCompsCount;
    int compsCount;
    QQueue<myMap>* expectForDownload;

    void changeCompsCount(int count);
    void send(int getterId, Program* sendingProgram);
    void sendProgram(int compId, Program* message);
    void addComputerInNetwork(OperatingSystem* os, int newCompId);
    void createNetwork();
    Virus* createVirus();
    void getLinksBetweenComps(QList<QString> startData);
    bool startDownload();
};

#endif // LocalNetwork_H
