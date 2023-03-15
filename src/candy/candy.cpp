#include "candy.hpp"
#include "./game-engine/GameEngine.hpp"
#include <iostream>
#include "../utils/interface.hpp"
using std::cin;
using std::cout;
using std::endl;

void Candy::start()
{
  while (true)
  {
    GameEngine ge;
    bool stop = false;
    while (!stop)
    {
      ge.start();

      cout << "Apakah anda ingin mengakhiri permainan?[" << cred() << "ya" << reset() << "/" << cblue() << "tidak" << reset() << "]" << endl;
      string choice;

      cin >> choice;

      if (choice == "ya")
      {
        stop = true;
      }
    }
  }
}