#include "PlayerCandy.hpp"
#include "../../base/exception/DeckException.hpp"
#include "../exception/AbilitiesException.hpp"
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

void help()
{
    cout << "List perintah:" << endl
         << "1. next" << endl
         << "2. double" << endl
         << "3. half" << endl
         << "4. <ability-name>" << endl
         << "List ability:" << endl
         << "1. Abilityless" << endl
         << "2. Quadruple" << endl
         << "3. Quarter" << endl
         << "4. Reroll" << endl
         << "5. Reverse" << endl
         << "6. Swap Card" << endl
         << "7. Switch" << endl;
}

// boolean isFirstRound
// Minta input, validasi, terus kalau ability ada try nya di exception in
PlayerAction PlayerCandy::getAction(bool isFirstRound)
{
    string input;
    bool valid = false;
    if (isFirstRound)
    {
        while (!valid)
        {
            help();
            cin >> input;
            if ((input == "Abilityless") || (input == "Quadruple") || (input == "Quarter") || (input == "Reroll") || (input == "Reverse") || (input == "Swap Card") || (input == "Switch"))
            {
                valid = true;
                try
                {
                    this->abilityStatus->activeOrThrow();
                    this->abilityStatus->notUsedOrThrow();
                    this->abilityStatus->haveOrThrow(input);
                    return PlayerAction::ability;
                }
                catch (AbilityException &e)
                {
                    cout << e.what() << endl;
                }
            }
            else if (input == "next")
            {
                valid = true;
                return PlayerAction::next;
            }
            else if (input == "double")
            {
                valid = true;
                return PlayerAction::dbl;
            }
            else if (input == "half")
            {
                valid = true;
                return PlayerAction::half;
            }
            else
            {
                cout << "Masukan salah! Harap ulangi masukan" << endl;
            }
        }
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