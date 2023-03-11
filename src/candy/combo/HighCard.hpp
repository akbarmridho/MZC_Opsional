#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Comboable.hpp"
#include "../card/CardCandy.hpp"
#include <iostream>
#include <vector>
using std::vector;

class HighCard : virtual public Comboable {
protected:
    void computeCombo(vector<CardCandy>);
public:
    HighCard(const vector<CardCandy> &);
};

#endif