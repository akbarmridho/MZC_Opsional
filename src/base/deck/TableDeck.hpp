#ifndef TABLEDECK_HPP
#define TABLEDECK_HPP

#include "InventoryHolder.hpp"

template<class T>
class TableDeck : public InventoryHolder<T> {
public:
    void insertCard(T);

    vector<T> &getCards();
};

#endif
