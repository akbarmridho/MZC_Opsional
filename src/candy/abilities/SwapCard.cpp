#include "SwapCard.hpp"
#include "../exception/AbilitiesException.hpp"
#include "../../utils/interface.hpp"
#include "../../utils/interface.hpp"

#include <iostream>
#include <algorithm>

using std::back_inserter;
using std::cin;
using std::copy_if;
using std::cout;
using std::endl;

SwapCard::SwapCard(PlayerCandy **players) : AbilityCard("SWAP CARD") {
    this->players = new PlayerCandy *[7];
    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }
}

void SwapCard::use() {
    PlayerCandy *target[] = {nullptr, nullptr};

    vector<PlayerCandy *> selectablePlayers;

    copy_if(players, players + 7, back_inserter(selectablePlayers),
            [this](PlayerCandy *player) { return this->getOwner() != player; });

    for (int i = 0; i < 2; i++) {
        cout << "Silakan pilih pemain lain yang kartunya ingin anda tukar: " << endl;

        for (int j = 0; j < selectablePlayers.size(); j++) {
            PlayerCandy *player = selectablePlayers.at(j);
            cout << j + 1 << ". " << player->getName() << endl;
        }

        bool valid = false;
        while (!valid) {
            int val = getValidatedInt("> ");

            if (val < 1 || val > selectablePlayers.size()) {
                cout << "Masukan salah. Pilih ulang! " << endl;
            } else {
                target[i] = selectablePlayers[i];
                selectablePlayers.erase(selectablePlayers.begin() + i);
                valid = true;
            }
        }
    }

    int switchTarget[] = {-1, -1};

    for (int i = 0; i < 2; i++) {
        cout << "Silakan pilih kartu kanan/kiri " << *target[i] << endl;

        cout << "1. Kanan" << endl
             << "2. Kiri" << endl;

        bool valid = false;
        while (!valid) {
            int val = getValidatedInt("> ");

            if (val != 1 && val != 2) {
                cout << "Masukan salah. Pilih ulang! " << endl;
            } else {
                switchTarget[i] = val - 1;
                valid = true;
            }
        }
    }

    PlayerDeckCandy &deck1 = target[0]->getDeck();
    PlayerDeckCandy &deck2 = target[1]->getDeck();

    CardCandy c1 = deck1.removeCard(switchTarget[0]);
    CardCandy c2 = deck2.removeCard(switchTarget[1]);

    deck1.insertCard(c2);
    deck2.insertCard(c1);

    cout << "Kartu berhasil ditukar" << endl;

    getStatus().setUsed();
}

SwapCard::~SwapCard() {
    delete[] players;
}
