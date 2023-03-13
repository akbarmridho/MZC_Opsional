#include "Quadruple.hpp"
#include <iostream>
using std::cout;

Quadruple::Quadruple(PointManager *pm) : AbilityCard("quadruple")
{
  pointManager = pm;
}

void Quadruple::use()
{
  cout << *getOwner() << " melakukan QUADRUPLE! Poin hadiah naik dari " << pointManager->getCurrentRewardPoint() << " menjadi ";

  pointManager->multiplyReward(4);

  cout << pointManager->getCurrentRewardPoint() << "!\n";

  getStatus().setUsed();
}