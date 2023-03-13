#ifndef DECKMANAGER_HPP
#define DECKMANAGER_HPP

#include "../deck/GameDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"
#include "../player/PlayerCandy.hpp"

class DeckManager {
public:
    DeckManager();

    DeckManager(PlayerCandy *[7]);

    void resetDeck();

    void initializePlayerDeck(); // dipanggil ronde 1
    void openTableCard();

    GameDeckCandy &getGameDeck();

protected:
    PlayerCandy *players[7];
    GameDeckCandy gameDeck;
    TableDeckCandy tableDeck;
};

#endif