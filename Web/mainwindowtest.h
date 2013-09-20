#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QApplication>

#include "mainwindow.h"

class MainWindowTest : public QObject
{
   Q_OBJECT
public:
    explicit MainWindowTest(QObject * parent = 0) : QObject(parent) {}

private slots:
    void initTestCase()
    {
        myWindow = new MainWindow();
        click = "";
    }

    void cleanupTestCase()
    {
        delete myWindow;
    }

    void infectButtonSignal()
    {
        click = "infectButtonSignal";
    }

    void infectButtonClickedTest()
    {
        connect(myWindow, SIGNAL(wantMoreIllnesses()), this, SLOT(infectButtonSignal()));
        myWindow->infectButtonClicked();
        QVERIFY(click == "infectButtonSignal");
    }

    void newVirusButtonSignal()
    {
        click = "newVirusButtonSignal";
    }

    void newVirusButtonClickedTest()
    {
        connect(myWindow, SIGNAL(emitNewVirus()), this, SLOT(newVirusButtonSignal()));
        myWindow->newVirusButtonClicked();
        QVERIFY(click == "newVirusButtonSignal");
    }

private:
    QString click;
    MainWindow* myWindow;
};
