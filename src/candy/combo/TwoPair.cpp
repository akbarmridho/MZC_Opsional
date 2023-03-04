#include "TwoPair.hpp"
#include <iostream>

TwoPair::TwoPair(const PlayerDeckCandy &playerDeck, const TableDeckCandy &tableDeck)
    : Comboable(3, playerDeck, tableDeck){};

void TwoPair::computeCombo(const PlayerDeckCandy &, const TableDeckCandy &)
{
}