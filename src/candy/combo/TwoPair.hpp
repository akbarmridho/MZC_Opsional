#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Comboable.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class TwoPair : virtual public Comboable 
{
    public:
        explicit TwoPair(const vector<CardCandy> &);
};

#endif