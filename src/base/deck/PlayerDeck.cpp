#include "PlayerDeck.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"

template<class T>
void PlayerDeck<T>::insertCard(T card) {
    this->cards.push_back(card);
}

template<class T>
T PlayerDeck<T>::removeCard() {
    int lastIdx = this->getCount() - 1;
    return removeCard(lastIdx);
}

template<class T>
T PlayerDeck<T>::removeCard(int idx) {
    auto erased = this->get(idx);
    this->cards.erase(this->cards.begin() + idx);
    return erased;
}

template
class PlayerDeck<CardCandy>;

template
class PlayerDeck<CardCangkul>;