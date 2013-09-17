#ifndef DATA_H
#define DATA_H

#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

/**
 * @brief The Data class - class for working with files
 */
class Data
{
public:
    /**
     * @brief Data - empty constructor
     */
    Data();

    /**
     * @brief getStartData - read start data in startLines in string format
     */
    QList<QString> getStartData();

private:
    /**
     * @brief startLines - start data in string format
     */
    QList<QString> startLines;

    /**
     * @brief readFile - read start data from file
     */
    void readFile();
};

#endif // DATA_H
