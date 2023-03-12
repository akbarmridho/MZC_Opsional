#include "TableDeckCandy.hpp"

vector<CardCandy> const &TableDeckCandy::getCards() const
{
    return this->cards;
}

void TableDeckCandy::resetDeck()
{
    reset();
}