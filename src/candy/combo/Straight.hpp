#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "Comboable.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class Straight : public Comboable {
public:
    explicit Straight(const vector<CardCandy> &);
};

#endif