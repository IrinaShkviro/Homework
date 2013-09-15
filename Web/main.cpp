#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include "localnetwork.h"
#include "data.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LocalNetwork* myNet = new LocalNetwork();
    QObject::connect(myNet, SIGNAL(compsCountChanged(int)), &w, SLOT(showCompCountChanges(int)));
    QObject::connect(myNet, SIGNAL(infectedCompsCountChanged(int)), &w, SLOT(showInfectCompsChanges(int)));
    QObject::connect(&w, SIGNAL(wantMoreIllnesses()), myNet, SLOT(tryToSendProgram()));
    QObject::connect(&w, SIGNAL(emitNewVirus()), myNet, SLOT(pushVirusInRandomComp()));
    myNet->update();

    return a.exec();
}
