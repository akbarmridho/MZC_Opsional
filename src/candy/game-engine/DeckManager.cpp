#include "DeckManager.hpp"

DeckManager::DeckManager(PlayerCandy *players[7], GameDeckCandy gameDeck, TableDeckCandy tableDeck) : gameDeck(gameDeck), tableDeck(tableDeck)
{
    for (int i = 0; i < 7; i++)
    {
        this->players[i] = players[i];
    }
}

void DeckManager::resetDeck()
{
    // Resets the player deck
    CardCandy c;
    for (int i = 0; i < 7; i++)
    {
        c = players[i].removeCard();
        c = players[i].removeCard();
    }
    // Resets the table deck
    tableDeck.resetDeck();
    // Resets the game deck
}

void DeckManager::initializePlayerDeck()
{
    for (int i = 0; i < 7; i++)
    {
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
    }
}

void DeckManager::openTableCard()
{
    CardCandy c1 = gameDeck.popCard();
    tableDeck.insertCard(c1);
}