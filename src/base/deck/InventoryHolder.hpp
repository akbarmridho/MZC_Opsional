#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>

using std::vector;

template <class T>
class InventoryHolder
{
protected:
    vector<T> cards;

public:
    void reset();
    void sortCards();
    T& operator[](int);
    T& get(int);
    InventoryHolder<T> &operator+(InventoryHolder<T> &);
    InventoryHolder<T> &operator-(InventoryHolder<T> &);
    [[nodiscard]] int getCount() const;
};

#endif