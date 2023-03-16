#include "HighCard.hpp"
#include <algorithm>

HighCard::HighCard(const vector<CardCandy> &cards) : Comboable(1) {
    computeCombo(cards);
}

void HighCard::computeCombo(vector<CardCandy> cards) {
    sort(cards.begin(), cards.end(), [](CardCandy a, CardCandy b)
        { return ((a.getType() <= b.getType())); });
    
    stable_sort(cards.begin(), cards.end(), [](CardCandy a, CardCandy b)
        { return ((a.getNumber() >= b.getNumber())); });
    std::cout << std::endl;
    for (int i = 0; i <= 6; i++) {
        const CardCandy &card = cards[i];
        this->comboValue = (this->comboValue<<4) + card.getNumber();
        this->comboValue = (this->comboValue<<2) + card.getType();
    }
}