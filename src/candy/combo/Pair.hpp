#ifndef PAIR_HPP
#define PAIR_HPP

#include "Comboable.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class Pair : public Comboable {
public:
    explicit Pair(const vector<CardCandy> &);
};


#endif