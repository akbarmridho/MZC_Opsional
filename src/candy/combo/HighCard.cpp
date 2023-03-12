#include "HighCard.hpp"

HighCard::HighCard(const vector<CardCandy> &cards) : Comboable(1) {
    computeCombo(cards);
}

void HighCard::computeCombo(vector<CardCandy> cards) {
    double maxNum = 0;
    int idx = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i].getNumber() > maxNum) {
            maxNum = cards[i].getNumber();
            idx = i;
        }
    }
    this->comboValue = maxNum + (cards[idx].getType() * 0.03);
}