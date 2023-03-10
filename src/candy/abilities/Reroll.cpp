#include "Reroll.hpp"
#include "../exception/AbilitiesException.hpp"

Reroll::Reroll(GameDeckCandy *a) : AbilityCard("Reroll")
{
    this->gamedeck = a;
}

void Reroll::use()
{
    notUsedOrThrow();
    activeOrThrow();

    // Deletes the current main deck card
    PlayerDeckCandy &deck = this->getOwner()->getDeck();
    CardCandy c = deck.removeCard();
    c = deck.removeCard();

    // Insert from deck
    deck.insertCard(this->gamedeck->popCard());
    deck.insertCard(this->gamedeck->popCard());
}
