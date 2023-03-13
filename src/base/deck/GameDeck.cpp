#include "GameDeck.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"

template<class T>
T GameDeck<T>::popCard() {
    int lastIdx = this->getCount() - 1;
    auto erased = this->get(lastIdx);
    this->cards.erase(this->cards.begin() + lastIdx);

    return erased;
}

template
class GameDeck<CardCandy>;

template
class GameDeck<CardCangkul>;