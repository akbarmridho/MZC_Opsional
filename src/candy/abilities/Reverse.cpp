#include "Reverse.hpp"
#include <iostream>

Reverse::Reverse(RoundManager *rm) : AbilityCard("Reverse") {
  roundManager = rm;
}

void Reverse::use()
{
  notUsedOrThrow();
  activeOrThrow();
  std::cout << *getOwner() << " melakukan REVERSE!\n";
  roundManager->reversePlayer();

  setUsed();
}