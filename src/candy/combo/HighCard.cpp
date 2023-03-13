#include "HighCard.hpp"
#include <algorithm>

HighCard::HighCard(const vector<CardCandy> &cards) : Comboable(1) {
    computeCombo(cards);
}

void HighCard::computeCombo(vector<CardCandy> cards) {
    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         { return ((a < b) && (a.getType() < b.getType())); });
    this->comboValue = 0;
    for (int i = 0; i < 6; i++) {
        this->comboValue += ((cards[i].getNumber() * 10) + cards[i].getType());
    }
}