#ifndef PLAYERDECK_HPP
#define PLAYERDECK_HPP

#include "InventoryHolder.hpp"
#include "TableDeck.hpp"

template <class T>
class PlayerDeck : virtual public InventoryHolder<T>
{
public:
    void insertCard(T);
    /**
     * Remove card and return
     */
    T removeCard();
    /**
     * Remove card by index
     */
    T removeCard(int);
};

#endif