#ifndef COMBOABLE_HPP
#define COMBOABLE_HPP

#include <utility>
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class Comboable : virtual public Valuable
{
protected:
    int level;
    double comboValue;

public:
    Comboable(int level);
    Comboable(int level, double comboValue);
    virtual value_pair_t value() const;
};

#endif