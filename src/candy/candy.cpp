#include "candy.hpp"
#include "./game-engine/GameEngine.hpp"
#include <iostream>
#include "../utils/interface.hpp"
using std::cout;
using std::endl;

void Candy::start()
{
  while (true)
  {
    GameEngine ge;
    ge.start();

    cout << "Lanjut?\n";
    cout << "\t1. " << cgreen() << "Main lagi\n"
         << reset();
    cout << "\t2. " << cred() << "Main menu\n"
         << reset();
  }
}