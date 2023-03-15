#include "DeckManager.hpp"
#include "../../base/exception/DeckException.hpp"
#include "../../utils/interface.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

DeckManager::DeckManager(PlayerCandy *players[7]) {
    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }
}

void DeckManager::resetDeck() {
    // Resets the player deck
    for (int i = 0; i < 7; i++) {
        players[i]->getDeck().resetDeck();
    }
    // Resets the table deck
    tableDeck.resetDeck();
    // Resets the game deck

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
                clearTerminal();
            } catch (DeckException &e) {
                cout << "Pembacaan file gagal" << endl;
                cout << e.what() << endl;
            }
        } else {
            cout << "Pilihan salah" << endl;
        }
    }

    cout << "Kartu telah dibagikan!\n";
}

void DeckManager::initializePlayerDeck() {
    for (int i = 0; i < 7; i++) {
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
        this->players[i]->getDeck().insertCard(gameDeck.popCard());
        players[i]->updateTableDeck(&this->tableDeck);
    }
}

void DeckManager::openTableCard() {
    CardCandy c1 = gameDeck.popCard();
    tableDeck.insertCard(c1);
}

GameDeckCandy &DeckManager::getGameDeck() {
    return gameDeck;
}

DeckManager::DeckManager() {
}

void DeckManager::showTableStatus() {
    cout << "Kartu di meja:\n";
    for (auto &c: tableDeck.getCards()) {
        cout << "\t- " << c << endl;
    }
}
