#include "TableDeck.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"

template<class T>
vector<T> &TableDeck<T>::getCards() {
    return this->cards;
}

template<class T>
void TableDeck<T>::insertCard(T card) {
    this->cards.push_back(card);
}

template
class TableDeck<CardCandy>;

template
class TableDeck<CardCangkul>;
