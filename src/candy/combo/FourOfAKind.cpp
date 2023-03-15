#include "FourOfAKind.hpp"
#include <iostream>

using std::pair;
using std::make_pair;
using std::vector;

FourOfAKind::FourOfAKind(const vector<CardCandy> &cards)
    : Comboable(2, 0)
{
    using VectorPair = vector<pair<int, int>>;
    VectorPair cardBag(13, make_pair(0,0));


    for (const auto card : cards)
    {
        int cardNum = card.getNumber();
        int typeValue = 1<<card.getType();
        cardBag[cardNum - 1].first++;
        cardBag[cardNum - 1].second += typeValue;
    }

    int counter = 0;
    for (int i = 12; i >= 0; i--)
    {
        if (cardBag[i].first >= 4)
        {
            counter++;
            int cardNum = i + 1;
            int typeValue = cardBag[i].second;

            this->comboValue = this->comboValue * 100 + cardNum;
            this->comboValue = this->comboValue * 100 + typeValue;

            break;
        }
    }
}