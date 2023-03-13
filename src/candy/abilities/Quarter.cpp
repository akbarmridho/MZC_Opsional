#include "Quarter.hpp"
#include <iostream>

Quarter::Quarter(PointManager *pm) : AbilityCard("quarter")
{
  pointManager = pm;
}

void Quarter::use()
{
  std::cout << *getOwner();

  if (pointManager->getCurrentRewardPoint() >= 4)
  {
    std::cout << " melakukan QUARTER! Poin hadiah turun " << pointManager->getCurrentRewardPoint() << " menjadi ";
    pointManager->divideReward(4);
    std::cout << pointManager->getCurrentRewardPoint() << "!\n";
  }
  else
  {
    std::cout << " melakukan QUARTER! Sayangnya poin hadiah sudah bernilai kurang dari 4. Poin hadiah tidak berubah.. Giliran dilanjut\n";
  }

  getStatus().setUsed();
}