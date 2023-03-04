#include "Quadruple.hpp"
#include <iostream>
using std::cout;

Quadruple::Quadruple(GameEngine *ge) : AbilityCard("Quadruple", ge) {}

void Quadruple::use()
{
  notUsedOrThrow();
  activeOrThrow();
  PointManager pointManager = gameEngine->getPointManager();
  cout << *getOwner() << " melakukan QUADRUPLE! Poin hadiah naik dari " << pointManager.getCurrentRewardPoint() << " menjadi ";

  gameEngine->getPointManager().multiplyReward(4);

  cout << pointManager.getCurrentRewardPoint() << "!\n";

  setUsed();
}