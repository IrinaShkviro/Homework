#include <QCoreApplication>
#include <QtDebug>
#include "graph.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Graph* myGraph = new Graph();
    bool result = myGraph->assessResult();
    if (result) {
        qDebug() << "Yes";
    } else {
        qDebug() << "No";
    }
    
    return a.exec();
    return 0;
}
