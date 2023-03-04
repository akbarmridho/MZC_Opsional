#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP
#include "Comboable.hpp"

class FourOfAKind : virtual public Comboable
{
protected:
  void computeCombo(vector<CardCandy>);

public:
  FourOfAKind(const vector<CardCandy> &);
};

#endif