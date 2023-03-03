#include "TableDeck.hpp"

template <class T>
void TableDeck<T>::insertCard(T card) {
    this->cards.push_back(card);
}