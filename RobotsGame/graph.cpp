#include "graph.h"

Graph::Graph():
    robotsDestroy(false)
  , myNodes(new QList<GraphNode*>())
  , myNodesCount(0)
  , serviceNode(new GraphNode(0))
  , currentType(serviceNode->neither)
  , oddCount(0)
  , evenCount(0)
  , bothCount(0)
  , neitherCount(0)
{
    createGraph();
}

bool Graph::assessResult()
{
    if (myNodes->size() < 2) {
        return false;
    }
    markTypeOfNodes();
    countNodesOfEachType();
    if (neitherCount > 0) {
        return false;
    }
    if (bothCount > 0) {
        return true;
    }
    if (evenCount == 1 || oddCount == 1) {
        return false;
    }
    return true;
}

void Graph::theEnd()
{
    robotsDestroy = true;
}

void Graph::createGraph()
{
    WorkWithFile* myFile = new WorkWithFile();
    QList<QString> data = myFile->getStartData();
    bool ok;
    myNodesCount = data.takeAt(0).toInt(&ok);
    if (!ok) {
        return;
    }
    for (int i = 0; i < myNodesCount; i++) {
        GraphNode* curNode = new GraphNode(i + 1);
        myNodes->append(curNode);
    }
    connectEndSignals();
    for (int i = 0; i < myNodesCount; i++) {
        if (data.isEmpty()) {
            break;
        }
        myNodes->at(i)->addContacts(data.takeAt(0));
    }
    if (data.isEmpty()) {
        return;
    }
    QStringList robotsInString = data[0].split(",");
    while (!robotsInString.isEmpty()) {
        myNodes->at(robotsInString.takeAt(0).toInt())->changeBusy(true);
    }
}

void Graph::markTypeOfNodes()
{
    myNodes->takeAt(0)->changeTypeOfNode(serviceNode->odd);
    currentType = serviceNode->odd;
    QList<int> path;
    path.append(0);
    markContacts(0, path);
}

void Graph::markContacts(int nodeNumber, QList<int> path)
{
    if (robotsDestroy) {
        return;
    }
    if (currentType == serviceNode->odd) {
        currentType = serviceNode->even;
    } else {
        currentType = serviceNode->odd;
    }
    myNodes->at(nodeNumber)->changeTypeOfNode(currentType);
    if (path.contains(nodeNumber)) {
        return;
    }
    for (int i = 0; i < myNodes->at(nodeNumber)->contacts->size(); i++) {
        int contactNumber = myNodes->at(nodeNumber)->contacts->at(i);
        path.append(nodeNumber);
        markContacts(contactNumber, path);
    }
}

void Graph::connectEndSignals()
{
    for (int i = 0; i < myNodes->size(); i++) {
        connect(myNodes->at(i), SIGNAL(success()), this, SLOT(theEnd()));
    }
}

void Graph::countNodesOfEachType()
{
    for (int i = 0; i < myNodesCount; i++) {
        GraphNode* curNode = myNodes->at(i);
        if (!curNode->isBusy()) {
            continue;
        }
        switch (curNode->returnType())
        {
            case GraphNode::odd:
                oddCount++;
            case GraphNode::even:
                evenCount++;
            case GraphNode::both:
                bothCount++;
            case GraphNode::neither:
                neitherCount++;
        }
    }
}
