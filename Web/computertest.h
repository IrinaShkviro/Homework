#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "computer.h"

class ComputerTest : public QObject
{
   Q_OBJECT
public:
   explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initTestCase()
    {
        emptyComp = new Computer();
        pass = "";
    }

    void cleanupTestCase()
    {
        delete emptyComp;
    }

    void testOS()
    {
        OperatingSystem* linux = new LinuxOS();
        Computer* comp = new Computer(linux, 0);
        QVERIFY(comp->myOS == linux);
    }

    void testId()
    {
        int i = 5;
        Computer* comp = new Computer(new LinuxOS(), i);
        QVERIFY(comp->returnId() == i);
    }

    void illTest()
    {
        QVERIFY(emptyComp->amIIll() == false);
    }

    void infectTest()
    {
        emptyComp->infectIt();
        QVERIFY(emptyComp->amIIll() == true);
    }

    void getFromLocalTest()
    {
        Program* newProgram = new LinuxVirus();
        emptyComp->getFromLocalNetwork(newProgram);
        QVERIFY(emptyComp->programList.at(0) == newProgram);
    }

    void checkGetFromLocalSignal()
    {
        pass = "getFromLocalSignalTest";
    }

    void getFromLocalSignalTest()
    {
        connect(emptyComp, SIGNAL(triedToInfect(int)), this, SLOT(checkGetFromLocalSignal()));
        emptyComp->getFromLocalNetwork(new LinuxVirus());
        QVERIFY(pass == "getFromLocalSignalTest");
    }

    void connectToLocalTest()
    {
        Computer* comp = new Computer(new LinuxOS(), 4);
        QVERIFY(comp->amIConnectToLocal() == true);
    }

    void addContactListTest()
    {
        QList<int> contacts;
        contacts << 1 << 2 << 3;
        emptyComp->addContactList(contacts);
        QVERIFY(emptyComp->contactList == contacts);
    }

private:
    Computer* emptyComp;
    QString pass;
};
