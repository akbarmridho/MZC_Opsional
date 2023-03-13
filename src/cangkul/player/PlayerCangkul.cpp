#include "PlayerCangkul.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

PlayerCangkul::PlayerCangkul(string name) : Player(name) {
}

CardCangkul PlayerCangkul::selectCard() {
    int idx;
    bool valid = false;

    while (!valid) {
        cout << "Pilih kartu: " << endl;

        for (int i = 0; i < this->deck.getCount(); i++) {
            CardCangkul &card = this->deck[i];
            cout << i + 1 << ". " << card.getTypeString() << "-" << card.getNumber() << endl;
        }

        int number;
        cin >> number;

        if (number >= 1 && number <= this->deck.getCount()) {
            valid = true;
            idx = number - 1;
        } else {
            cout << "Nomor kartu salah!" << endl;
        }
    }

    return this->deck.popAt(idx);
}

CardCangkul PlayerCangkul::selectCardWithType(CardCangkulType type) {
    vector<int> idxMap;
    int idx;
    bool valid = false;

    while (!valid) {
        cout << "Pilih kartu: " << endl;

        int j = 0;

        for (int i = 0; i < this->deck.getCount(); i++) {
            CardCangkul &card = this->deck[i];

            if (card.getType() == type) {
                cout << j + 1 << ". " << card.getTypeString() << "-" << card.getNumber() << endl;
                j++;
                idxMap.push_back(i);
            }
        }

        int number;
        cin >> number;

        if (number >= 1 && number <= j) {
            valid = true;
            idx = number - 1;
        } else {
            cout << "Nomor kartu salah!" << endl;
        }
    }

    return this->deck.popAt(idxMap[idx]);
}

void PlayerCangkul::receiveCard(CardCangkul card) {
    this->deck.insertCard(card);
}

int PlayerCangkul::countCardWithType(CardCangkulType type) {
    int count = 0;

    for (int i = 0; i < this->deck.getCount(); i++) {
        if (this->deck[i].getType() == type) {
            count++;
        }
    }

    return count;
}