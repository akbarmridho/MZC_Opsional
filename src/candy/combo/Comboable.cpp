#include "Comboable.hpp"

value_pair_t Comboable::value()
{
    return value_pair_t{
        level,
        comboValue};
}

Comboable::Comboable(int level) : Comboable(level, 0)
{
}

Comboable::Comboable(int level, double comboValue)
{
    this->level = level;
    this->comboValue = comboValue;
}