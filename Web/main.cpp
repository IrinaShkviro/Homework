#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include "localnetwork.h"
#include "data.h"
#include "mainwindowtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTest test;
    QTest::qExec(&test);
   /* QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LocalNetwork* myNet = new LocalNetwork();
    QObject::connect(myNet, SIGNAL(compsCountChanged(int)), &w, SLOT(showCompCountChanges(int)));
    QObject::connect(myNet, SIGNAL(infectedCompsCountChanged(int)), &w, SLOT(showInfectCompsChanges(int)));
    QObject::connect(&w, SIGNAL(wantMoreIllnesses()), myNet, SLOT(tryToSendProgram()));
    QObject::connect(&w, SIGNAL(emitNewVirus()), myNet, SLOT(pushVirusInRandomComp()));
    QObject::connect(myNet, SIGNAL(success(bool)), &w, SLOT(assessSuccess(bool)));
    QObject::connect(myNet, SIGNAL(triedToInfect(int)), &w, SLOT(triedToInfect(int)));
    myNet->update();

    a.exec();
    delete myNet;*/
    return 0;
}
