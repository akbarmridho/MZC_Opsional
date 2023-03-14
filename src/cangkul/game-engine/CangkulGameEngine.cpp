#include "CangkulGameEngine.hpp"

#include <iostream>
#include "../player/PlayerCangkul.hpp"
#include "../../utils/interface.hpp"
#include "../../base/exception/DeckException.hpp"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

CangkulGameEngine::CangkulGameEngine() {
    this->players = new PlayerCangkul *[4];
}

void CangkulGameEngine::main() {
    cout << "Selamat datang di permatinan cangkul!" << endl
         << endl;

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

    string choice;
    bool valid = false;

    while (!valid) {
        cout << "Apakah anda ingin mengacak atau mengambil urutan kartu dari file? [acak/file]" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == "acak") {
            gameDeck.shuffle();
            valid = true;
        } else if (choice == "file") {
            cout << "Masukkan nama file: " << endl;
            cout << "> ";
            string path;
            cin >> path;

            try {
                gameDeck.fromFile(path);
                valid = true;
            } catch (DeckException &e) {
                cout << "Pembacaan file gagal" << endl;
                cout << e.what() << endl;
            }
        } else {
            cout << "Pilihan salah" << endl;
        }
    }
    this->tableDeck.clearWaste();
    this->tableDeck.reset();
    this->leaderboards.clear();
    this->lostLeaderboards.clear();
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

    clearTerminal();

    while (this->turns.size() > 1) {

        for (auto &player: turns) {
            cout << "Giliran pemain " << player->getName() << endl;
            cout << "Anda memiliki kartu sebanyak " << player->deck.getCount() << " buah" << endl;

            if (this->tableDeck.getCount() == 0) {
                CardCangkul card = player->selectCard();
                this->tableDeck.insertCard({player, card});
            } else {
                this->tableDeck.printTable();
                CardCangkulType type = this->tableDeck.getCurrentType();

                while (player->countCardWithType(type) == 0 &&
                       (this->gameDeck.getCount() != 0 || this->tableDeck.getWasteCount() != 0)) {
                    if (this->gameDeck.getCount() == 0) {
                        auto waste = this->tableDeck.getWaste();
                        this->gameDeck.shuffle(waste);
                        this->tableDeck.clearWaste();
                    }

                    CardCangkul card = this->gameDeck.popCard();
                    cout << "Anda menyangkul kartu dan mendapatkan " << card.getTypeString() << card.getNumberReps()
                         << endl;
                    player->receiveCard(card);
                }

                if (this->gameDeck.getCount() == 0 && player->countCardWithType(type) == 0) {
                    cout << "Kartu pada deck telah habis. Pemain otomatis kalah" << endl;
                    this->lostLeaderboards.push_back(player);
                } else {
                    CardCangkul card = player->selectCardWithType(type);
                    this->tableDeck.insertCard({player, card});
                }
            }

            clearTerminal();
        }

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

    clearTerminal();
    cout << "Game berakhir" << endl;
    cout << "Urutan pemenang: " << endl;
    int i;
    for (i = 0; i < this->leaderboards.size(); i++) {
        cout << i + 1 << ". " << *this->leaderboards[i] << endl;
    }
    for (auto it = this->lostLeaderboards.rbegin(); it != lostLeaderboards.rend(); it++) {
        cout << i + 1 << ". " << (**it) << endl;
        i++;
    }

}

CangkulGameEngine::~CangkulGameEngine() {
    for (int i = 0; i < 4; i++) {
        delete this->players[i];
    }

    delete[] this->players;
}
