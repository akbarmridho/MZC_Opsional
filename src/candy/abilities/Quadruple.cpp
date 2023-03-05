#include "Quadruple.hpp"
#include <iostream>
using std::cout;

Quadruple::Quadruple(PointManager *pm) : AbilityCard("Quadruple")
{
  pointManager = pm;
}

void Quadruple::use()
{
  notUsedOrThrow();
  activeOrThrow();
  cout << *getOwner() << " melakukan QUADRUPLE! Poin hadiah naik dari " << pointManager->getCurrentRewardPoint() << " menjadi ";

  pointManager->multiplyReward(4);

  cout << pointManager->getCurrentRewardPoint() << "!\n";

  setUsed();
}