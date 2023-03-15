#include "Comboable.hpp"

value_pair_t Comboable::value() const
{
    return value_pair_t{
        level,
        comboValue};
}

Comboable::Comboable(int level) : Comboable(level, 0)
{
}

Comboable::Comboable(int level, unsigned long long int comboValue)
{
    this->level = level;
    this->comboValue = comboValue;
}