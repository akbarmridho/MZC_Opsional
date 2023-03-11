#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP
#include "Comboable.hpp"

#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class TwoPair : virtual public Comboable
{
protected:
    void computeCombo(const PlayerDeckCandy &, const TableDeckCandy &);

public:
    TwoPair(const PlayerDeckCandy &, const TableDeckCandy &);
};

#endif