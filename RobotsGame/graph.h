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

    /**
     * @brief assessResult
     * @return true if such order exist
     */
    bool assessResult();

private:
    /**
     * @brief myNodes - list of nodes included in graph
     */
    QList<GraphNode*>* myNodes;

    /**
     * @brief serviceNode - node for service aims
     */
    GraphNode* serviceNode;

    /**
     * @brief currentType - new type of node which is assessing now
     */
    GraphNode::TypeOfNode currentType;

    /**
     * @brief myNodesCount - amount os nodes in this graph
     */
    int myNodesCount;

    /**
     * @brief oddCount - count of nodes with type 'odd'
     */
    int oddCount;

    /**
     * @brief evenCount - count of nodes with type 'even'
     */
    int evenCount;

    /**
     * @brief bothCount - count of nodes with type 'both'
     */
    int bothCount;

    /**
     * @brief neitherCount - count of nodes with type 'neither'
     */
    int neitherCount;

    /**
     * @brief createGraph - create graph with conditions from start data file
     */
    void createGraph();

    /**
     * @brief markTypeOfNodes - assess type of each node
     */
    void markTypeOfNodes();

    /**
     * @brief markContacts - recursive function, which go around graph and assess type of node
     * @param nodeNumber - number of node, which is assessing
     * @param path - list of nodes which were assessed before
     */
    void markContacts(int nodeNumber, QList<int> path);

    /**
     * @brief countNodesOfEachType - count amount of nodes of each type
     */
    void countNodesOfEachType();

    /**
     * @brief changeCurrentType -  change current type from odd to even and backwards
     */
    void changeCurrentType();
};

#endif // GRAPH_H
