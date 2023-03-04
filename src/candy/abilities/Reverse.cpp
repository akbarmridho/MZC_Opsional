#include "Reverse.hpp"
#include <iostream>

Reverse::Reverse(GameEngine *ge) : AbilityCard("Reverse", ge) {}

void Reverse::use()
{
  notUsedOrThrow();
  activeOrThrow();
  RoundManager roundManager = gameEngine->getRoundManager();
  std::cout << *getOwner() << " melakukan REVERSE!\n";
  roundManager.reversePlayer();

  setUsed();
}