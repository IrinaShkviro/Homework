#ifndef SAVER_H
#define SAVER_H

#include <QMap>
#include "computer.h"

/**
 * @brief The Saver class - keep association id-computer
 */
class Saver
{
public:
    /**
     * @brief Saver - constructor
     */
    Saver();

    /**
     * @brief instance
     * @return simple example of this class
     */
    static Saver* instance();

    /**
      * @brief returnCompById
      * @param id
      * @return computer with id=id
      */
     Computer* returnCompById(int id);

     /**
      * @brief addComputer add comp in list of associates
      * @param comp
      */
     void addComputer(Computer* comp);

     /**
      * @brief myCompList
      * @return list of computers which were saved in it
      */
     QList<Computer*> myCompList() const;

private:
     QMap<int, Computer*>* computers;
};

#endif // SAVER_H
