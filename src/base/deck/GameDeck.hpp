#ifndef GAMEDECK_HPP
#define GAMEDECK_HPP

#include "./InventoryHolder.hpp"

template <class T>
class GameDeck : virtual public InventoryHolder<T>
{
public:
    virtual T popCard();

protected:
    // dipanggil oleh modifikasi reset deck
    virtual void shuffle() = 0;
    virtual void from_file() = 0;
};

#endif