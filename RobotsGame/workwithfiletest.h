#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "workwithfile.h"

class WorkWithFileTest : public QObject
{
    Q_OBJECT
public:
    explicit WorkWithFileTest(QObject * parent = 0) : QObject(parent) {}

private slots:
    void initTestCase()
    {
        myFile = new WorkWithFile();
        startData = myFile->getStartData();
    }

    void cleanupTestCase()
    {
        delete myFile;
    }

    void startLine0Test()
    {
        QVERIFY(startData.at(0) == "6");
    }

    void startLine1Test()
    {
        QVERIFY(startData.at(1) == "2,6");
    }

    void startLine2Test()
    {
        QVERIFY(startData.at(2) == "1,3");
    }

    void startLine3Test()
    {
        QVERIFY(startData.at(3) == "2,4,5");
    }

    void startLine4Test()
    {
        QVERIFY(startData.at(4) == "3,5");
    }

    void startLine5Test()
    {
        QVERIFY(startData.at(5) == "3,4,6");
    }

    void startLine6Test()
    {
        QVERIFY(startData.at(6) == "1,5");
    }

    void startLine7Test()
    {
        QVERIFY(startData.at(7) == "1,3,5");
    }


private:
    WorkWithFile* myFile;
    QList<QString> startData;
};
