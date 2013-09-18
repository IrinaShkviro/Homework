#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "data.h"

class DataTest : public QObject
{
   Q_OBJECT
public:
   explicit DataTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initCaseTest()
    {
        data = new Data();
    }

    void cleanupTestCase()
    {
        delete data;
    }

    void getStartData()
    {
        stringData = data->getStartData();
    }

    void countOfCompsTest()
    {
        getStartData();
        QVERIFY(stringData.at(0) == "5");
    }

    void connectedWithThirdComp()
    {
        getStartData();
        QVERIFY(stringData.at(3) == "4,5");
    }

private:
    Data* data;
    QList<QString> stringData;
};

