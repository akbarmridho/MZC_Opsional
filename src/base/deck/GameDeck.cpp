#include "GameDeck.hpp"

template <class T>
T GameDeck<T>::popCard() {
    int lastIdx = this->getCount() - 1;
    auto erased = this->get(lastIdx);
    this->cards.erase(lastIdx);

    return erased;
}