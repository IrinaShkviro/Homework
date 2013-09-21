#ifndef WORKWITHFILE_H
#define WORKWITHFILE_H

#include <QFile>
#include <QByteArray>
#include <QDebug>

/**
 * @brief The WorkWithFile class for working with file that consider
 *  information about graph and robots positions
 */
class WorkWithFile
{
public:
    WorkWithFile();

    /**
     * @brief getStartData
     * @return useful information about graph and robots in list of strings
     */
    QList<QString> getStartData();

private:

    /**
     * @brief read - read file with start data
     */
    void read();

    /**
     * @brief dataInString - start data writed in list of strings
     */
    QList<QString> dataInString;
};

#endif // WORKWITHFILE_H
