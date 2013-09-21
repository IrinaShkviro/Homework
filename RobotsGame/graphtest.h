#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "graph.h"

class GraphTest : public QObject
{
    Q_OBJECT
public:
    explicit GraphTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void initTestCase()
    {
        graph = new Graph();
    }

    void cleanupTestCase()
    {
        delete graph;
    }

    void assessResultTest()
    {
        QVERIFY(graph->assessResult() == true);
    }

private:
    Graph* graph;
};
