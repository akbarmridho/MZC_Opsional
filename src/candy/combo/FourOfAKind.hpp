#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP

#include "Comboable.hpp"

#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class FourOfAKind : public Comboable {
protected:
    void computeCombo(vector<CardCandy>);

public:
    FourOfAKind(const vector<CardCandy> &);
};

#endif