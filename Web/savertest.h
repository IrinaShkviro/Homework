#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "saver.h"

class SaverTest : public QObject
{
    Q_OBJECT
public:
    explicit SaverTest(QObject* parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        mySaver = new Saver();
    }

    void cleanup()
    {
        delete mySaver;
    }

    void addCompSizeTest()
    {
        Computer* comp = new Computer(new LinuxOS, 5);
        mySaver->addComputer(comp);
        QVERIFY(mySaver->myCompList().size() == 1);
    }

    void addCompObjectTest()
    {
        Computer* comp = new Computer(new LinuxOS, 5);
        mySaver->addComputer(comp);
        QVERIFY(mySaver->myCompList().at(0) == comp);
    }

    void returnCompByIdTest()
    {
        Computer* comp = new Computer(new LinuxOS, 5);
        mySaver->addComputer(comp);
        QVERIFY(mySaver->returnCompById(5) == comp);
    }

private:
    Saver* mySaver;
};
