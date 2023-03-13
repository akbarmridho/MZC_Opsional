#include "DeckManager.hpp"

DeckManager::DeckManager(PlayerCandy *players[7]) {
    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }
}

void DeckManager::resetDeck() {
    // Resets the player deck
    for (int i = 0; i < 7; i++) {
        players[i]->getDeck().resetDeck();
    }
    // Resets the table deck
    tableDeck.resetDeck();
    // Resets the game deck
    gameDeck.shuffle();
}

void DeckManager::initializePlayerDeck() {
    for (int i = 0; i < 7; i++) {
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
    }
}

void DeckManager::openTableCard() {
    CardCandy c1 = gameDeck.popCard();
    tableDeck.insertCard(c1);
}

GameDeckCandy &DeckManager::getGameDeck() {
    return gameDeck;
}

DeckManager::DeckManager() {

}
