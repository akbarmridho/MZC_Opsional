#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "Comboable.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class StraightFlush : virtual public Comboable 
{
    public:
        explicit StraightFlush(const vector<CardCandy> &);
};


#endif