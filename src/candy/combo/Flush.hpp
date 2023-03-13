#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Comboable.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class Flush : public Comboable {
protected:
    void computeCombo(vector<CardCandy>);

public:
    explicit Flush(const vector<CardCandy> &);
};


#endif