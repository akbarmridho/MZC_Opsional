#include "InventoryHolder.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"
#include "../../cangkul/player/PlayerCangkul.hpp"
#include <utility>
#include <algorithm>

using std::pair;

template<class T>
void InventoryHolder<T>::reset() {
    cards.clear();
}

template<class T>
void InventoryHolder<T>:: sortCards() {
    std::sort(cards.begin(), cards.end(), [](T &a, T&b){
        return a > b;
    });
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

template<class T>
InventoryHolder<T> &InventoryHolder<T>::operator+(InventoryHolder<T> &other) {
    auto card = other.cards.rbegin();
    this->cards.push_back(*card);
    other.cards.pop_back();
    return *this;
}

template<class T>
InventoryHolder<T> &InventoryHolder<T>::operator-(InventoryHolder<T> &other) {
    auto card = this->cards.rbegin();
    other.cards.push_back(*card);
    this->cards.pop_back();
    return *this;
}

template
class InventoryHolder<CardCandy>;

template
class InventoryHolder<CardCangkul>;

template
class InventoryHolder<pair<PlayerCangkul *, CardCangkul>>;