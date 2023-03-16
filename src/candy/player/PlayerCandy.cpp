#include "PlayerCandy.hpp"
#include "../../base/exception/DeckException.hpp"
#include "../exception/AbilitiesException.hpp"
#include "../exception/DeckCandyException.hpp"
#include "../../utils/string.hpp"
#include "../../utils/interface.hpp"
#include "../../utils/debug.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

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

void help(bool isFirstRound)
{
    cout << "List perintah:" << endl
         << "  1. NEXT" << endl
         << "  2. DOUBLE" << endl
         << "  3. HALF" << endl
         << "  4. GAME STATUS" << endl;

    if (!isFirstRound)
    {
        cout << "  4. <ability-name>" << endl
             << "List ability:" << endl
             << "  1. ABILITYLESS" << endl
             << "  2. QUADRUPLE" << endl
             << "  3. QUARTER" << endl
             << "  4. REROLL" << endl
             << "  5. REVERSE" << endl
             << "  6. SWAP CARD" << endl
             << "  7. SWITCH" << endl;
    }
}

// boolean isFirstRound
// Minta input, validasi, terus kalau ability ada try nya di exception in
PlayerAction PlayerCandy::getAction(bool isFirstRound)
{
#ifdef DEBUG
#ifdef NEXT_ALL
    return PlayerAction::next;
#endif
#endif
    cout << "Masukkan command\n";
    string input;
    bool valid = false;
    while (!valid)
    {
        cout << "> ";
        getline(cin, input);
        upper(input);
        if (input == "HELP")
        {
            help(isFirstRound);
        }
        else if (!isFirstRound &&
                 ((input == "ABILITYLESS") || (input == "QUADRUPLE") || (input == "QUARTER") || (input == "REROLL") ||
                  (input == "REVERSE") || (input == "SWAP CARD") || (input == "SWITCH")))
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
                cout << endl << cred() << e.what() <<  reset() << endl << endl;
                return PlayerAction::invalid;
            }
        }
        else if (input == "NEXT")
        {
            valid = true;
            return PlayerAction::next;
        }
        else if (input == "DOUBLE")
        {
            valid = true;
            return PlayerAction::dbl;
        }
        else if (input == "HALF")
        {
            valid = true;
            return PlayerAction::half;
        }
        else if (input == "GAME STATUS")
        {
            valid = true;
            return PlayerAction::status;
        }
        else
        {
            cout << "Masukan salah! Harap ulangi masukan (command help untuk menampilkan list command)" << endl;
        }
    }
    return PlayerAction::invalid;
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

void PlayerCandy::showStatus(bool isFirstRound)
{
    cout << "Kartu kamu: \n";
    for (int i = 0; i < 2; i++)
    {
        CardCandy &c = this->deck.get(i);
        cout << "\t- " << c << endl;
    }

    if (!isFirstRound)
    {
        cout << endl;
        this->abilityStatus->showStatus();
    }
}