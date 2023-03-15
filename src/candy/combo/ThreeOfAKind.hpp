#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "Comboable.hpp"
#include "../card/CardCandy.hpp"
#include <iostream>
#include <vector>

using std::vector;

class ThreeOfAKind : public Comboable {
public:
    ThreeOfAKind(const vector<CardCandy> &);
};

#endif