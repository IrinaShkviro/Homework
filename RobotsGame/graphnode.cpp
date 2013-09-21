#include "graphnode.h"

GraphNode::GraphNode(int number):
    myNumber(number)
  , myNodeType(neither)
  , contacts(new QList<int>())
  , busy(false)
{
}

GraphNode::TypeOfNode GraphNode::returnType()
{
    return myNodeType;
}

int GraphNode::returnNumber()
{
    return myNumber;
}

void GraphNode::changeTypeOfNode(GraphNode::TypeOfNode newType)
{
    if (myNodeType == newType) {
        return;
    }
    if (myNodeType == neither) {
        myNodeType = newType;
        return;
    }
    myNodeType = both;
    emit success();
}

void GraphNode::addContacts(QString contactLine)
{
    QStringList nodesInString = contactLine.split(",");
    while (!nodesInString.isEmpty()) {
        contacts->append(nodesInString[0].toInt());
        nodesInString.removeAt(0);
    }
}

bool GraphNode::isBusy()
{
    return busy;
}

void GraphNode::changeBusy(bool isBusy)
{
    busy = isBusy;
}
