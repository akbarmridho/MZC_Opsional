#ifndef DECKMANAGER_HPP
#define DECKMANAGER_HPP

#include "../deck/GameDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"
#include "../player/PlayerCandy.hpp"
class DeckManager
{
public:
    void resetDeck();
    void initializePlayerDeck(); // dipanggil ronde 1
    void openTableCard();

protected:
    PlayerCandy *players;
    GameDeckCandy gameDeck;
    TableDeckCandy tableDeck;
};

#endif