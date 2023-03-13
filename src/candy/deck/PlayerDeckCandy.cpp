#include "PlayerDeckCandy.hpp"
#include "../combo/Comboable.hpp"
#include "../combo/TwoPair.hpp"
#include "../combo/FourOfAKind.hpp"
#include "../../base/exception/DeckException.hpp"
#include <algorithm>

using std::min;
using std::sort;

PlayerDeckCandy::PlayerDeckCandy() {
    comboComputed = false;
}

PlayerDeckCandy::~PlayerDeckCandy() {
    while (!combos.empty()) {
        Comboable *combo = combos.back();
        combos.pop_back();
        delete combo;
    }
}

vector<CardCandy> const &PlayerDeckCandy::getCards() const {
    return cards;
}

void PlayerDeckCandy::resetDeck() {
    reset();
    comboComputed = false;
    while (!combos.empty()) {
        Comboable *combo = combos.back();
        combos.pop_back();
        delete combo;
    }
}

void PlayerDeckCandy::pushOrDeleteCombo(Comboable *combo) {
    if (combo->value().second != 0)
        combos.push_back(combo);
    else
        delete combo;
}

void PlayerDeckCandy::computeCombos(TableDeckCandy &tableDeck) {
    // cache computation
    if (comboComputed)
        return;
    vector<CardCandy> cards;
    cards.insert(cards.end(), this->cards.begin(), this->cards.end());
    cards.insert(cards.end(), tableDeck.getCards().begin(), tableDeck.getCards().end());

    // do this for all the combos
    pushOrDeleteCombo(new FourOfAKind(cards));

    // sort descending
    sort(combos.begin(), combos.end(), [](Comboable *a, Comboable *b) { return (*a) > (*b); });
}

bool PlayerDeckCandy::operator<(PlayerDeckCandy &other) {
    if (!comboComputed || !other.comboComputed)
        throw NoComputedCombosException();
    int minSize = min(combos.size(), other.combos.size());
    for (int i = 0; i < minSize; i++) {
        Comboable *c1 = combos[i];
        Comboable *c2 = other.combos[i];
        if (*c1 == *c2)
            continue;
        return *c1 < *c2;
    }
    return combos.size() < other.combos.size();
}

bool PlayerDeckCandy::operator>(PlayerDeckCandy &other) {
    if (!comboComputed || !other.comboComputed)
        throw NoComputedCombosException();
    int minSize = min(combos.size(), other.combos.size());
    for (int i = 0; i < minSize; i++) {
        Comboable *c1 = combos[i];
        Comboable *c2 = other.combos[i];
        if (*c1 == *c2)
            continue;
        return *c1 > *c2;
    }
    return combos.size() > other.combos.size();
}
