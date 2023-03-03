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
    T& operator[](int);
    T& get(int);
    [[nodiscard]] int getCount() const;
};

#endif