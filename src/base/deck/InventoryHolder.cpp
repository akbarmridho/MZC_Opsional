#include "InventoryHolder.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"

template<class T>
void InventoryHolder<T>::reset() {
    cards.clear();
}

template<class T>
T &InventoryHolder<T>::operator[](int idx) {
    return cards[idx];
}

template<class T>
T &InventoryHolder<T>::get(int idx) {
    return cards[idx];
}

template<class T>
int InventoryHolder<T>::getCount() const {
    return cards.size();
}

template
class InventoryHolder<CardCandy>;

template
class InventoryHolder<CardCangkul>;