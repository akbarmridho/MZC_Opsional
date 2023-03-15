#include "Reroll.hpp"
#include "../exception/AbilitiesException.hpp"
#include "../../utils/interface.hpp"
#include "../../utils/string.hpp"
#include <iostream>

using namespace std;

Reroll::Reroll(DeckManager *a) : AbilityCard("reroll")
{
    this->deckManager = a;
}

void Reroll::use()
{
    // Deletes the current main deck card
    PlayerDeckCandy &deck = this->getOwner()->getDeck();
    deck.removeCard();
    deck.removeCard();

    GameDeckCandy &gameDeck = this->deckManager->getGameDeck();

    // Insert from deck
    deck.insertCard(gameDeck.popCard());
    deck.insertCard(gameDeck.popCard());

    cout << cblue(true) << "JENG JENG JENG deck mu telah di reroll" << reset() << endl;
    this->getOwner()->showStatus(true);

    this->getStatus().setUsed();
}
