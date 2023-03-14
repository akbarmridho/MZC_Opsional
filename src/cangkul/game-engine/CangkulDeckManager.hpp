#ifndef CANGKULDECKMANAGER_HPP
#define CANGKULDECKMANAGER_HPP

#include "../deck/GameDeckCangkul.hpp"
#include "../deck/TableDeckCangkul.hpp"

class CangkulDeckManager
{
private:
  GameDeckCangkul gameDeck;
  TableDeckCangkul tableDeck;
  PlayerCangkul *players[4];

public:
  CangkulDeckManager();
  CangkulDeckManager(PlayerCangkul *players[4]);

  void resetDeck();
  vector<PlayerCangkul *> resolveTableCards();
  bool isTableDeckEmpty() const;
  bool isGameDeckEmpty() const;
  bool isWasteEmpty() const;
  bool getFromPlayer(PlayerCangkul *player);
};

#endif