#include "CangkulGameEngine.hpp"

#include <iostream>
#include "../player/PlayerCangkul.hpp"
#include "../../utils/interface.hpp"
#include "../../base/exception/DeckException.hpp"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

CangkulGameEngine::CangkulGameEngine()
{
    this->players = new PlayerCangkul *[4];
}

void CangkulGameEngine::main()
{
    cout << "Selamat datang di permatinan cangkul!" << endl
         << endl;

    for (int i = 0; i < 4; i++)
    {
        string name;
        cout << "Masukkan nama pemain ke-" << i + 1 << ":" << endl
             << "> ";
        cin >> name;
        this->players[i] = new PlayerCangkul(name);
    }

    CangkulDeckManager dm(players);
    this->deckManager = dm;

    bool stop = false;

    while (!stop)
    {
        beginGame();

        cout << "Apakah anda ingin mengakhiri permainan?[ya/tidak]" << endl;
        string choice;

        cin >> choice;

        if (choice == "ya")
        {
            stop = true;
        }
    }
}

void CangkulGameEngine::beginGame()
{
    this->deckManager.resetDeck();
    this->leaderboards.clear();
    this->lostLeaderboards.clear();
    this->turns.clear();

    for (int i = 0; i < 4; i++)
    { // initial turn
        this->turns.push_back(this->players[i]);
    }

    clearTerminal();

    while (this->turns.size() > 1)
    {
        runRound();
    }

    this->leaderboards.push_back(this->turns[0]);

    clearTerminal();
    cout << "Game berakhir" << endl;
    cout << "Urutan pemenang: " << endl;
    int i;
    for (i = 0; i < this->leaderboards.size(); i++)
    {
        cout << i + 1 << ". " << *this->leaderboards[i] << endl;
    }
    for (auto it = this->lostLeaderboards.rbegin(); it != lostLeaderboards.rend(); it++)
    {
        cout << i + 1 << ". " << (**it) << endl;
        i++;
    }
}

void CangkulGameEngine::runRound()
{
    for (auto &player : turns)
    {
        cout << "Giliran pemain " << player->getName() << endl;
        cout << "Anda memiliki kartu sebanyak " << player->deck.getCount() << " buah" << endl;

        bool success = deckManager.getFromPlayer(player);
        if (!success)
            this->lostLeaderboards.push_back(player);

        clearTerminal();
    }

    auto newTurns = this->deckManager.resolveTableCards();

    std::vector<PlayerCangkul *> nextPlayers;
    std::copy_if(newTurns.begin(), newTurns.end(), std::back_inserter(nextPlayers),
                 [](PlayerCangkul *p)
                 { return p->deck.getCount() != 0; });

    std::vector<PlayerCangkul *> winnerPlayers;
    std::copy_if(newTurns.begin(), newTurns.end(), std::back_inserter(winnerPlayers),
                 [](PlayerCangkul *p)
                 { return p->deck.getCount() == 0; });

    for (auto &player : winnerPlayers)
    {
        cout << "Kartu pemain " << player->getName() << " telah habis" << endl;
        this->leaderboards.push_back(player);
    }

    this->turns = nextPlayers;

    cout << "Pemenang ronde ini adalah " << this->turns[0]->getName() << endl;
}

CangkulGameEngine::~CangkulGameEngine()
{
    for (int i = 0; i < 4; i++)
    {
        delete this->players[i];
    }

    delete[] this->players;
}
