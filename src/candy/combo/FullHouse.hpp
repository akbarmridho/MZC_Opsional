#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Comboable.hpp"

class FullHouse : virtual public Comboable {
public:
    explicit FullHouse(const vector<CardCandy> &);
};


#endif
