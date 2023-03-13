#include "CangkulGameEngine.hpp"

#include <iostream>
#include "../player/PlayerCangkul.hpp"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

CangkulGameEngine::CangkulGameEngine() {
    this->players = new PlayerCangkul *[4];
}

void CangkulGameEngine::main() {
    for (int i = 0; i < 4; i++) {
        string name;
        cout << "Masukkan nama pemain ke-" << i + 1 << ":" << endl;
        cin >> name;
        this->players[i] = new PlayerCangkul(name);
    }

    bool stop = false;

    while (!stop) {
        beginGame();

        cout << "Apakah anda ingin mengakhiri permainan?[ya/tidak]" << endl;
        string choice;

        cin >> choice;

        if (choice == "ya") {
            stop = true;
        }
    }
}

void CangkulGameEngine::beginGame() {
    this->gameDeck.shuffle(); // shuffle deck
    this->tableDeck.clearWaste();
    this->tableDeck.reset();
    this->leaderboards.clear();
    this->turns.clear();

    for (int j = 0; j < 4; j++) {
        this->players[j]->deck.reset();
        for (int i = 0; i < 7; i++) {
            this->players[j]->receiveCard(this->gameDeck.popCard());
        }
    }

    for (int i = 0; i < 4; i++) { // initial turn
        this->turns.push_back(this->players[i]);
    }

    while (this->turns.size() > 1) {
        for (auto &player: turns) {
            cout << "Giliran pemain " << player->getName() << endl;

            if (this->tableDeck.getCount() == 0) {
                CardCangkul card = player->selectCard();
                this->tableDeck.insertCard({player, card});
            } else {
                this->tableDeck.printTable();
                CardCangkulType type = this->tableDeck.getCurrentType();

                while (player->countCardWithType(type) == 0) {
                    if (this->gameDeck.getCount() == 0) {
                        auto waste = this->tableDeck.getWaste();
                        this->gameDeck.shuffle(waste);
                        this->tableDeck.clearWaste();
                    }

                    CardCangkul card = this->gameDeck.popCard();
                    cout << "Anda menyangkul kartu dan mendapatkan " << card.getTypeString() << "-" << card.getNumber()
                         << endl;
                    player->receiveCard(card);
                }

                CardCangkul card = player->selectCardWithType(type);
                this->tableDeck.insertCard({player, card});
            }
        }

        this->tableDeck.printTable();
        auto newTurns = this->tableDeck.resolveCards();

        std::vector<PlayerCangkul *> nextPlayers;
        std::copy_if(newTurns.begin(), newTurns.end(), std::back_inserter(nextPlayers),
                     [](PlayerCangkul *p) { return p->deck.getCount() != 0; });

        std::vector<PlayerCangkul *> winnerPlayers;
        std::copy_if(newTurns.begin(), newTurns.end(), std::back_inserter(winnerPlayers),
                     [](PlayerCangkul *p) { return p->deck.getCount() == 0; });

        for (auto &player: winnerPlayers) {
            cout << "Kartu pemain " << player->getName() << " telah habis" << endl;
            this->leaderboards.push_back(player);
        }

        this->turns = nextPlayers;
        
        cout << "Pemenang ronde ini adalah " << this->turns[0]->getName() << endl;
    }

    this->leaderboards.push_back(this->turns[0]);

    cout << "Urutan pemenang: " << endl;
    for (int i = 0; i < this->leaderboards.size(); i++) {
        cout << i + 1 << ". " << this->leaderboards[i]->getName() << endl;
    }
}

CangkulGameEngine::~CangkulGameEngine() {
    for (int i = 0; i < 4; i++) {
        delete this->players[i];
    }

    delete[] this->players;
}
