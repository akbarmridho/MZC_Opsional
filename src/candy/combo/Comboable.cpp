#include "Comboable.hpp"

value_pair Comboable::value()
{
    return value_pair{
        level,
        comboValue};
}

Comboable::Comboable(const PlayerDeckCandy &playerDeck, const TableDeckCandy &tableDeck)
{
    computeCombo(playerDeck, tableDeck);
};