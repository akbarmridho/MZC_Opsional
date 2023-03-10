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
    virtual void computeCombo(const PlayerDeckCandy &, const TableDeckCandy &) = 0;

public:
    Comboable(int level, const PlayerDeckCandy &, const TableDeckCandy &);
    virtual value_pair_t value();
};

#endif