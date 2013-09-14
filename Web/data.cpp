#include "data.h"

Data::Data()
{
}

QList<QString> Data::getStartData()
{
    startLines.clear();
    readFile();
    for (int i = 0; i < 5; i++) {
        startLines.removeAt(0);
    }
    return startLines;
}

void Data::readFile()
{
    QFile fileForReading("forRead.txt");
    if (!fileForReading.open(QIODevice::ReadOnly)) {
        return;
    }
    QTextStream startFile(&fileForReading);
    while (!startFile.atEnd()) {
        QString line = startFile.readLine();
        startLines.append(line);
    }
}
