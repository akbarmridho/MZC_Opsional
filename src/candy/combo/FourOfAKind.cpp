#include "FourOfAKind.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
using std::sort;

FourOfAKind::FourOfAKind(const vector<CardCandy> &cards)
    : Comboable(8, 0)
{
    computeCombo(cards);
};

void FourOfAKind::computeCombo(vector<CardCandy> cards) // copy so that cards can be sorted freely
{

    // sort by value
    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         { return a < b; });
    int same = 0;
    CardCandyType lastType;
    for (int i = 0; i < cards.size(); i++)
    {
        const CardCandy &card = cards[i];
        if (same == 0 || card.getType() != lastType)
        {
            lastType = card.getType();
            same = 1;
        }
        else
        {
            same++;
        }
        if (same == 4)
        {
            double cardValue = 0;
            for (int j = 0; j < 4; j++)
            {
                cardValue += cards[i - 3 + j].value().second * pow(10.0, 3.0 * j);
            }
            this->comboValue = cardValue;
            break;
        }
    }
}