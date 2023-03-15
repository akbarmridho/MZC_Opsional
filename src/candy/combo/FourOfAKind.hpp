#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP

#include "Comboable.hpp"

#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class FourOfAKind : public Comboable {
public:
    FourOfAKind(const vector<CardCandy> &);
};

#endif