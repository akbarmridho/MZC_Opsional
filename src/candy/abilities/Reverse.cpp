#include "Reverse.hpp"
#include <iostream>

Reverse::Reverse(RoundManager *rm) : AbilityCard("reverse")
{
  roundManager = rm;
}

void Reverse::use()
{
  std::cout << *getOwner() << " melakukan REVERSE!\n";
  roundManager->reversePlayer();

  getStatus().setUsed();
}