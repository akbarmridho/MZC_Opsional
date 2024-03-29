#include "Abilityless.hpp"
#include "../exception/AbilitiesException.hpp"
#include <iostream>
#include <algorithm>
#include "../../utils/interface.hpp"

using std::cout;
using std::cin;
using std::endl;

Abilityless::Abilityless(PlayerCandy **players) : AbilityCard("ABILITYLESS") {
    this->players = new PlayerCandy *[7];
    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }
}

void Abilityless::use() {
    vector<PlayerCandy *> selectablePlayers;
    copy_if(players, players + 7, back_inserter(selectablePlayers),
            [this](PlayerCandy *player) { return this->getOwner() != player; });

    if (all_of(selectablePlayers.begin(), selectablePlayers.end(),
               [](PlayerCandy *player) { return player->getAbility()->getUsed(); })) {
        cout
                << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia\n";
        getStatus().setUsed();
        return;
    }

    cout << "Silakan pilih pemain lain yang kartu abilitynya ingin dimatikan: " << endl;
    for (int i = 0; i < selectablePlayers.size(); i++) {
        PlayerCandy *player = selectablePlayers[i];
        cout << i + 1 << ". " << player->getName() << endl;
    }

    PlayerCandy *target;
    bool valid = false;
    while (!valid) {
        int val = getValidatedInt("> ");
        

        if (val < 1 || val > selectablePlayers.size()) {
            cout << "Masukan salah. Pilih ulang! " << endl;
        } else {
            target = selectablePlayers[val - 1];
            valid = true;
        }
    }
    if (target->getAbility()->getUsed()) {
        cout << "Kartu ability " << *target << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia\n";
    } else {
        target->getAbility()->deactivate();
        cout << "Kartu ability " << *target << " telah dimatikan.\n";
    }

    getStatus().setUsed();
}

Abilityless::~Abilityless() {
    delete[] players;
}
