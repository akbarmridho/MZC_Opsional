#include "Comboable.hpp"

value_pair_t Comboable::value()
{
    return value_pair_t{
        level,
        comboValue};
}

Comboable::Comboable(int level, const PlayerDeckCandy &playerDeck, const TableDeckCandy &tableDeck)
{
    this->level = level;
    computeCombo(playerDeck, tableDeck);
};