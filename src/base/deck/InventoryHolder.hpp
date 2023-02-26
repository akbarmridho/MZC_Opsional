#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>

using std::vector;

#include "../base/card/Card.hpp"

template <class T>
class InventoryHolder
{
protected:
    vector<T> cards;

public:
    virtual void resetDeck() = 0;
};

#endif