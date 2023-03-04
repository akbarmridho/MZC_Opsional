#include "FullHouse.hpp"
#include <map>
#include <utility>

using std::map;
using std::pair;

FullHouse::FullHouse(const vector<CardCandy> &cards) : Comboable(7) {
    map<int, int> counter;

    for (auto &card: cards) {
        if (counter.find(card.getNumber()) == counter.end()) {
            counter.insert(pair<int, int>(card.getNumber(), 1));
        } else {
            counter[card.getNumber()]++;
        }
    }

    // find the highest three pair
    int maxThree = -1;
    for (auto &each: counter) {
        if (each.second >= 3) {
            if (each.first > maxThree) {
                maxThree = each.first;
            }
        }
    }

    if (maxThree == -1) {
        return; // no fullhouse
    }

    counter.erase(maxThree);

    // find the highest two pair
    int maxTwo = -1;
    for (auto &each: counter) {
        if (each.second >= 2) {
            if (each.first > maxTwo) {
                maxTwo = each.first;
            }
        }
    }

    if (maxTwo == -1) {
        return; // no fullhouse
    }

    counter.erase(maxTwo);

    this->comboValue = maxThree;
}
