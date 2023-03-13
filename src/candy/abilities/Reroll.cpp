#include "Reroll.hpp"
#include "../exception/AbilitiesException.hpp"

Reroll::Reroll(DeckManager *a) : AbilityCard("Reroll") {
    this->deckManager = a;
}

void Reroll::use() {
    this->getStatus().notUsedOrThrow();
    this->getStatus().activeOrThrow();

    // Deletes the current main deck card
    PlayerDeckCandy &deck = this->getOwner()->getDeck();
    deck.removeCard();
    deck.removeCard();

    GameDeckCandy &gameDeck = this->deckManager->getGameDeck();

    // Insert from deck
    deck.insertCard(gameDeck.popCard());
    deck.insertCard(gameDeck.popCard());

    this->getStatus().setUsed();
}

