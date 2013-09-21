#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QObject>

/**
 * @brief The GraphNode class - element of graph with own number
 */
class GraphNode : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief GraphNode
     * @param number - number of element in graph
     */
    GraphNode(int number);

    /**
     * @brief The TypeOfNode enum - type for define statement of this node
     */
    enum TypeOfNode
    {
        odd,
        even,
        both,
        neither
    };

    /**
     * @brief contacts - list of nodes which have links between them and this node
     */
    QList<int> contacts;

    /**
     * @brief returnType
     * @return type of this node
     */
    TypeOfNode returnType();

    /**
     * @brief returnNumber
     * @return number in graph
     */
    int returnNumber();

    /**
     * @brief changeTypeOfNode - changes type of node
     * @param newType - type of node after this operation
     */
    void changeTypeOfNode(TypeOfNode newType);

    /**
     * @brief addContacts
     * @param contactLine - string, which consider information about nodes
     *  which are connected with this node
     */
    void addContacts(QString contactLine);

    /**
     * @brief isBusy
     * @return true if one of robots stays in this node
     */
    bool isBusy();

    /**
     * @brief changeBusy
     * @param isBusy - true if one of robots stays in this node
     */
    void changeBusy(bool isBusy);

private:

    /**
     * @brief myNodeType - type of this node
     */
    TypeOfNode myNodeType;

    /**
     * @brief myNumber - number in graph
     */
    int myNumber;

    /**
     * @brief busy - true if one of robots stays on this node
     */
    bool busy;
};

#endif // GRAPHNODE_H
