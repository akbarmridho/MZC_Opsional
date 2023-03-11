#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "Comboable.hpp"
#include "../card/CardCandy.hpp"
#include <iostream>
#include <vector>
using std::vector;

class ThreeOfAKind : virtual public Comboable
{
protected:
  void computeCombo(vector<CardCandy>);

public:
  ThreeOfAKind(const vector<CardCandy> &);
};

#endif