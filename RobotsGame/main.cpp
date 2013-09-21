#include <QCoreApplication>
#include <QtDebug>
#include "graph.h"

#include "workwithfiletest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WorkWithFileTest test;
    QTest::qExec(&test);
    /*QCoreApplication a(argc, argv);
    Graph* myGraph = new Graph();
    bool result = myGraph->assessResult();
    if (result) {
        qDebug() << "Yes";
    } else {
        qDebug() << "No";
    }
    
    return a.exec();*/
    return 0;
}
