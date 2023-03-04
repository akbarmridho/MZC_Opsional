#ifndef FOUROFAKIND_HPP
#define FOUROFAKIND_HPP
#include "Comboable.hpp"

class FourOfAKind : virtual public Comboable
{

public:
  static vector<FourOfAKind *> getCombos(const vector<CardCandy> &);
  FourOfAKind(double comboValue);
};

#endif