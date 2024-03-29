#include "Quarter.hpp"
#include <iostream>

Quarter::Quarter(PointManager *pm) : AbilityCard("QUARTER")
{
  pointManager = pm;
}

void Quarter::use()
{
  std::cout << *getOwner();

  if (pointManager->getCurrentRewardPoint() > 1)
  {
    std::cout << " melakukan QUARTER! Poin hadiah turun " << pointManager->getCurrentRewardPoint() << " menjadi ";
    pointManager->divideReward(4);
    std::cout << pointManager->getCurrentRewardPoint() << "!\n";
  }
  else
  {
    std::cout << " melakukan QUARTER! Sayangnya poin hadiah sudah 1. Poin hadiah tidak berubah.. Giliran dilanjut\n";
  }

  getStatus().setUsed();
}