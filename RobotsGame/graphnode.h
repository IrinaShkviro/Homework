#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QObject>

class GraphNode : public QObject
{
    Q_OBJECT
public:
    GraphNode(int number);
    enum TypeOfNode
    {
        odd,
        even,
        both,
        neither
    };
    QList<int>* contacts;
    TypeOfNode returnType();
    int returnNumber();
    void changeTypeOfNode(TypeOfNode newType);
    void addContacts(QString contactLine);
    bool isBusy();
    void changeBusy(bool isBusy);

signals:
    void success();

private:
    TypeOfNode myNodeType;
    int myNumber;
    bool busy;
};

#endif // GRAPHNODE_H
