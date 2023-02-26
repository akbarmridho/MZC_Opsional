#ifndef TABLEDECK_HPP
#define TABLEDECK_HPP

template <class T>
class TableDeck : virtual public InventoryHolder<T>
{
public:
    void insertCard(T);
};

#endif
