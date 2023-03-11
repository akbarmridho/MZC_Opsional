#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP
#include "Comboable.hpp"

class ThreeOfAKind : virtual public Comboable
{
protected:
  void computeCombo(vector<CardCandy>);

public:
  ThreeOfAKind(const vector<CardCandy> &);
};

#endif