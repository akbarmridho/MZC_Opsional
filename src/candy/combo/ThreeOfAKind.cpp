#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(const vector<CardCandy> &cards) : Comboable(4) {
    computeCombo(cards);
}

void ThreeOfAKind::computeCombo(vector<CardCandy> cards)
{
    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         { return a < b; });
         
    int same = 0;
    CardCandyType lastType;
    for (int i = 0; i < cards.size(); i++)
    {
        const CardCandy &card = cards[i];
        if (same == 0 || (card.getType() != lastType))
        {
            lastType = card.getType();
            same = 1;
        }
        else
        {
            same++;
        }
        if (same == 3)
        {
            this->comboValue = card.value().second;
            break;
        }
    }
}