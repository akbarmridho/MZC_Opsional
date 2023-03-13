#include "PlayerCandy.hpp"
#include "../../base/exception/DeckException.hpp"
#include <iostream>

using namespace std;

PlayerCandy::PlayerCandy() : Player("Default")
{
}

PlayerCandy::PlayerCandy(string name) : Player(name)
{
}

PlayerCandy::~PlayerCandy()
{
}

void PlayerCandy::receiveCard(CardCandy card)
{
    this->deck.insertCard(card);
}

void PlayerCandy::receiveAbility(AbilityStatus *ac)
{
    this->abilityStatus = ac;
}
AbilityStatus *PlayerCandy::getAbility() const
{
    return this->abilityStatus;
}

PlayerDeckCandy &PlayerCandy::getDeck()
{
    return this->deck;
}

void PlayerCandy::updateTableDeck(TableDeckCandy *tc)
{
    this->tableDeck = tc;
}

// boolean isFirstRound
PlayerAction PlayerCandy::getThenRunAction(bool isFirstRound)
{
    if (isFirstRound)
    {
    }
    else
    {
    }
}

bool PlayerCandy::operator>(PlayerCandy &other)
{
    this->deck.computeCombos(*this->tableDeck);
    other.deck.computeCombos(*this->tableDeck);

    return this->deck > other.deck;
}

bool PlayerCandy::operator<(PlayerCandy &other)
{
    this->deck.computeCombos(*this->tableDeck);
    other.deck.computeCombos(*this->tableDeck);

    return this->deck < other.deck;
}

bool PlayerCandy::operator==(PlayerCandy &other)
{
    this->deck.computeCombos(*this->tableDeck);
    other.deck.computeCombos(*this->tableDeck);
    return !(this->deck < other.deck) && !(this->deck > other.deck);
}