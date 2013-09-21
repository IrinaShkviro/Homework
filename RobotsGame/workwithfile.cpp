#include "workwithfile.h"

WorkWithFile::WorkWithFile()
{
}

QList<QString> WorkWithFile::getStartData()
{
    dataInString.clear();
    read();
    for (int i = 0; i < 4; i++) {
        dataInString.removeAt(0);
    }
    return dataInString;
}

void WorkWithFile::read()
{
    QFile fileForReading(":/startData.txt");
    if (!fileForReading.open(QIODevice::ReadOnly)) {
        return;
    }
    QTextStream startFile(&fileForReading);
    while (!startFile.atEnd()) {
        QString line = startFile.readLine();
        dataInString.append(line);
    }
}
