#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "localnetwork.h"

class LocalNetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit LocalNetworkTest(QObject * parent = 0) : QObject(parent) {}

private slots:

    void initTestCase()
    {
        myNet = new LocalNetwork();
        triedToInfectId = 0;
        justInfectedId = 0;
        connect(myNet, SIGNAL(triedToInfect(int)), this, SLOT(triedToInfect(int)));
        connect(myNet, SIGNAL(infectedCompsCountChanged(int)), this, SLOT(justInfected(int)));
        connect(myNet, SIGNAL(compsCountChanged(int)), this, SLOT(getSignal()));
        myNet->update();
    }

    void cleanupTestCase()
    {
        delete myNet;
    }

    void getSignal()
    {
        pass = true;
    }

    void updateTest()
    {
        myNet->update();
        QVERIFY(pass == true);
    }

    void triedToInfect(int id)
    {
        triedToInfectId = id;
    }

    void justInfected(int id)
    {
        justInfectedId = id;
    }

    void step1Test()
    {
        myNet->pushVirusInRandomComp();
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 1);
    }

    void step2Test()
    {
        myNet->pushVirusInRandomComp();
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 2);
    }

    void step3Test()
    {
        myNet->pushVirusInRandomComp();
        myNet->tryToSendProgram();
        QVERIFY(justInfectedId == 4);
    }

    void step4Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 1);
    }

    void step5Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 3);
    }

    void step6Test()
    {
        myNet->pushVirusInRandomComp();
        myNet->tryToSendProgram();
        QVERIFY(justInfectedId == 3);
    }

    void step7Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 2);
    }

    void step8Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(triedToInfectId == 4);
    }

    void step9Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(justInfectedId == 5);
    }

    void step10Test()
    {
        myNet->tryToSendProgram();
        QVERIFY(justInfectedId == 1);
    }

private:
    bool pass = false;
    int triedToInfectId;
    int justInfectedId;
    LocalNetwork* myNet;

};
