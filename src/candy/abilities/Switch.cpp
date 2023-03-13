#include "Switch.hpp"
#include "../exception/AbilitiesException.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Switch::Switch(PlayerCandy **a) : AbilityCard("Switch") {
    this->players = new PlayerCandy *[7];

    for (int i = 0; i < 7; i++) {
        this->players[i] = a[i];
    }
}

void Switch::use() {
    this->getStatus().notUsedOrThrow();
    this->getStatus().activeOrThrow();

    PlayerCandy *target;

    // Get all selectable player
    vector<PlayerCandy *> selectablePlayers;

    // All selectable players are players except owner
    copy_if(players, players + 7, back_inserter(selectablePlayers),
            [this](PlayerCandy *player) { return this->getOwner() != player; });

    // Print list semua pemain
    cout << "List Pemain: " << endl;
    int i = 1;

    for (auto &ply: selectablePlayers) {
        cout << i << ". " << ply->getName() << endl;
        i++;
    }

    // Pemilihan pemain
    bool valid = false;
    int value;
    while (!valid) {
        cout << "Silahkan pilih pemain untuk menukar kartu Anda: ";
        cin >> value;

        // Validasi input
        if (value < 1 || value > selectablePlayers.size()) {
            cout << endl
                 << "Masukan salah, harap ulangi input";
        } else {
            // Input sudah valid
            valid = true;
            target = selectablePlayers[value];
        }
    }

    // Lakukan penukaran
    PlayerDeckCandy &deck1 = this->getOwner()->getDeck();
    PlayerDeckCandy &deck2 = target->getDeck();

    CardCandy c1 = deck1.removeCard(0);
    CardCandy c2 = deck1.removeCard(1);
    CardCandy c3 = deck2.removeCard(0);
    CardCandy c4 = deck2.removeCard(1);

    deck1.insertCard(c3);
    deck1.insertCard(c4);
    deck2.insertCard(c1);
    deck2.insertCard(c2);

    cout << "Switch dengan " << selectablePlayers[value]->getName() << " berhasil dilakukan" << endl;

    this->getStatus().setUsed();
}

Switch::~Switch() {
    delete[] this->players[];
}
