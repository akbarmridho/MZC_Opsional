#ifndef DECKMANAGER_HPP
#define DECKMANAGER_HPP

#include "../deck/GameDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"
#include "../player/PlayerCandy.hpp"
#include "../card/CardCandy.hpp"
class DeckManager
{
public:
    /**
     * @brief Construct a new Deck Manager object
     *
     * @param players
     * @param gameDeck
     * @param tableDeck
     */
    DeckManager(PlayerCandy *players[7], GameDeckCandy gameDeck, TableDeckCandy tableDeck);
    /**
     * @brief resets all the deck
     *
     */
    void resetDeck();
    /**
     * @brief Initialize players deck
     *
     */
    void initializePlayerDeck(); // dipanggil ronde 1
    /**
     * @brief Open a table card
     *
     */
    void openTableCard();

protected:
    PlayerCandy *players[7];
    GameDeckCandy gameDeck;
    TableDeckCandy tableDeck;
};

#endif