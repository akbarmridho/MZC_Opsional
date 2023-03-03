#include "Comboable.hpp"

value_pair_t Comboable::value()
{
    return value_pair_t{
        level,
        comboValue};
}

Comboable::Comboable(const PlayerDeckCandy &playerDeck, const TableDeckCandy &tableDeck)
{
    computeCombo(playerDeck, tableDeck);
};