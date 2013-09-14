#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <QObject>
#include <QString>
#include <QGraphicsItem>
#include <QList>
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

private:
    int compsCount;
    QList<Virus*> virusList;
    void send(int getterId, Program* sendingProgram);
    void connectSignalsFromComps();
    void sendProgram(int compId, Program* message);
    void addComputerInNetwork(OperatingSystem* os, int newCompId);
    void createNetwork();
    void createVirus();
    void getLinksBetweenComps(QList<QString> startData);
};

#endif // LocalNetwork_H
