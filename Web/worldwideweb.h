#ifndef WORLDWIDEWEB_H
#define WORLDWIDEWEB_H

#include "network.h"

class WorldWideWeb : public Network
{
public:
    WorldWideWeb();

private:
    QList<int> contentList;
};

#endif // WORLDWIDEWEB_H
