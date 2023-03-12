#include "Straight.hpp"
#include <iostream>
#include <algorithm>

using std::make_pair;
using std::max;

Straight::Straight(const vector<CardCandy> &cards)
    : Comboable(5, 0)
{
    using VectorPair = vector<pair<int, int>>;
    VectorPair cardBag(13, make_pair(0,0));


    for (const auto card : cards)
    {
        int cardNum = card.getNumber();
        int typeValue = 1<<card.getType();
        cardBag[cardNum - 1].first++;
        cardBag[cardNum - 1].second = max(cardBag[cardNum - 1].second, typeValue);
    }

    int count = 0;
    int i = 12;
    for (i; i > 0; i--)
    {
        if (cardBag[i].first == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == 5) {break;}
        }
    }
    if (count == 5)
    {
        int index_end = i;
        for (i + 4; i >= index_end; i--)
        {
            this->comboValue = this->comboValue * 100 + cardBag[i].first;
            this->comboValue = this->comboValue * 10 + cardBag[i].second;
        }
    }
    

}