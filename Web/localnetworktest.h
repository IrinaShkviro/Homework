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
    void getSignal()
    {
        pass = true;
    }

    void updateTest()
    {
        LocalNetwork* myNet = new LocalNetwork();
        myNet->update();
        QVERIFY(pass == true);
    }

private:
    bool pass = false;

};
