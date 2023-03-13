#include "PlayerCandy.hpp"
#include "../../base/exception/DeckException.hpp"
#include "../exception/AbilitiesException.hpp"
#include "../exception/DeckCandyException.hpp"
#include "../../utils/string.hpp"
#include "../../utils/interface.hpp"
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
         << "\t1. next" << endl
         << "\t2. double" << endl
         << "\t3. half" << endl
         << "\t4. game status" << endl;

    if (!isFirstRound)
    {
        cout << "\t4. <ability-name>" << endl
             << "List ability:" << endl
             << "\t1. Abilityless" << endl
             << "\t2. Quadruple" << endl
             << "\t3. Quarter" << endl
             << "\t4. Reroll" << endl
             << "\t5. Reverse" << endl
             << "\t6. Swap Card" << endl
             << "\t7. Switch" << endl;
    }
}

// boolean isFirstRound
// Minta input, validasi, terus kalau ability ada try nya di exception in
PlayerAction PlayerCandy::getAction(bool isFirstRound)
{
    cout << "Masukkan command\n";
    string input;
    bool valid = false;
    while (!valid)
    {
        cout << "> ";
        getline(cin, input);
        lower(input);
        if (input == "help")
        {
            help(isFirstRound);
        }
        else if (!isFirstRound &&
                 ((input == "abilityless") || (input == "quadruple") || (input == "quarter") || (input == "reroll") ||
                  (input == "reverse") || (input == "swap card") || (input == "switch")))
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
        else if (input == "game status")
        {
            valid = true;
            return PlayerAction::status;
        }
        else
        {
            cout << "Masukan salah! Harap ulangi masukan (command help untuk menampilkan list command)" << endl;
        }
    }
    return PlayerAction::next;
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
        cout << "\t- ";
        c.print();
        cout << endl;
    }

    if (!isFirstRound)
    {
        this->abilityStatus->showStatus();
    }
}