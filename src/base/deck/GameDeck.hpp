#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include "./InventoryHolder.hpp"
#include <string>

using std::string;

template<class T>
class GameDeck : virtual public InventoryHolder<T> {
public:
    virtual T popCard();

public:
    virtual void shuffle() = 0;

    virtual void fromFile(const string &) = 0;
};

#endif