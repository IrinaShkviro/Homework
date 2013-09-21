#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>

#include "workwithfile.h"
#include "graphnode.h"

class Graph : public QObject
{
    Q_OBJECT
public:
    Graph();
    bool assessResult();

public slots:
    void theEnd();

private:
    QList<GraphNode*>* myNodes;
    GraphNode* serviceNode;
    GraphNode::TypeOfNode currentType;
    bool robotsDestroy;
    int myNodesCount;
    int oddCount;
    int evenCount;
    int bothCount;
    int neitherCount;
    void createGraph();
    void markTypeOfNodes();
    void markContacts(int nodeNumber, QList<int> path);
    void connectEndSignals();
    void countNodesOfEachType();
};

#endif // GRAPH_H
