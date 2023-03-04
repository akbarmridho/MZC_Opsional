#include "Quarter.hpp"
#include <iostream>

Quarter::Quarter(GameEngine *ge) : AbilityCard("Quarter", ge) {}

void Quarter::use()
{
  notUsedOrThrow();
  activeOrThrow();
  PointManager pointManager = gameEngine->getPointManager();

  if (pointManager.getCurrentRewardPoint() >= 4) {
    std::cout << *getOwner() << " melakukan QUARTER! Poin hadiah turun " << pointManager.getCurrentRewardPoint() << " menjadi ";
    gameEngine->getPointManager().multiplyReward(0.25);
    std::cout << pointManager.getCurrentRewardPoint() << "!\n";
  } else {
    std::cout << *getOwner() << 
    " melakukan QUARTER! Sayangnya poin hadiah sudah bernilai kurang dari 4. Poin hadiah tidak berubah.. Giliran dilanjut\n";
  }

  setUsed();
}