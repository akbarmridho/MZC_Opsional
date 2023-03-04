#include "Abilityless.hpp"
#include "../exception/AbilitiesException.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

Abilityless::Abilityless(GameEngine *ge) : AbilityCard("Abilityless", ge) {}

void Abilityless::use()
{
  if (this->getUsed())
  {
    throw UsedCardException(this->getName());
  }

  PlayerCandy **players = this->gameEngine->getPlayers();

  vector<PlayerCandy *> selectablePlayers;
  copy_if(players, players + 7, back_inserter(selectablePlayers), [this](PlayerCandy *player)
          { return this->getOwner() != player; });

  if (all_of(selectablePlayers.begin(), selectablePlayers.end(), [](PlayerCandy *player)
             { return player->getAbility()->getUsed(); }))
  {
    cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia\n";
    setUsed();
    return;
  }

  cout << "Silakan pilih pemain lain yang kartu abilitynya ingin dimatikan: " << endl;
  for (int i = 0; i < selectablePlayers.size(); i++)
  {
    PlayerCandy *player = selectablePlayers[i];
    cout << i + 1 << ". " << player->getName() << endl;
  }

  PlayerCandy *target;
  bool valid = false;
  while (!valid)
  {
    int val;
    cout << "> ";
    cin >> val;

    if (val < 1 || val > selectablePlayers.size())
    {
      cout << "Masukan salah. Pilih ulang! " << endl;
    }
    else
    {
      target = selectablePlayers[val - 1];
      valid = true;
    }
  }
  if (target->getAbility()->getUsed())
  {
    cout << "Kartu ability " << target->getName() << " telah dipakai debelumnya. Yah, sayang penggunaan kartu ini sia-sia\n";
  }
  else
  {
    target->getAbility()->deactivate();
    cout << "Kartu ability " << target->getName() << " telah dimatikan.\n";
  }

  setUsed();
}