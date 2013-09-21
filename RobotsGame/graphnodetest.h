#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "graphnode.h"

class GraphNodeTest : public QObject
{
    Q_OBJECT
public:
    explicit GraphNodeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initTestCase()
    {
        myNode = new GraphNode(1);
    }

    void cleanupTestCase()
    {
        delete myNode;
    }

    void returnTypeTest()
    {
        QVERIFY(myNode->returnType() == myNode->neither);
    }

    void returnNumberTest()
    {
        QVERIFY(myNode->returnNumber() == 1);
    }

    void changeTypeOfNodeTest()
    {
        myNode->changeTypeOfNode(myNode->odd);
        QVERIFY(myNode->returnType() == myNode->odd);
    }

    void addContactsTest()
    {
        myNode->addContacts("1,2,3");
        QList<int> myContacts;
        myContacts << 1 << 2 << 3;
        QVERIFY(myContacts == myNode->contacts);
    }

    void isBusyTest()
    {
        QVERIFY(myNode->isBusy() == false);
    }

    void changeBusyTest()
    {
        myNode->changeBusy(true);
        QVERIFY(myNode->isBusy() == true);
    }

private:
    GraphNode* myNode;
};
