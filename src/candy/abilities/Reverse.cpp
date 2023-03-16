#include "Reverse.hpp"
#include <iostream>

Reverse::Reverse(RoundManager *rm) : AbilityCard("REVERSE")
{
  roundManager = rm;
}

void Reverse::use()
{
  std::cout << *getOwner() << " melakukan REVERSE!\n";
  roundManager->reversePlayer();

  getStatus().setUsed();
}