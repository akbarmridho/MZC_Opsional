#include "TwoPair.hpp"
#include <iostream>
#include <math.h>

using std::pair;
using std::make_pair;
using std::vector;

TwoPair::TwoPair(const vector<CardCandy> &cards)
    : Comboable(3, 0)
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
        if (cardBag[i].first >= 2)
        {
            counter++;
            int cardNum = i + 1;
            int typeValue = cardBag[i].second;

            this->comboValue = (this->comboValue * 100) + cardNum;
            this->comboValue = (this->comboValue *= 100) + typeValue;

            if (counter == 3)
            {
                break;
            }
        }
    }
    int doubleCount = counter;
    while (counter < 3)
    {
        counter++;
        this->comboValue *= 10000;
    }

    if ((doubleCount <= 1))
    {
        this->comboValue = 0;
    }
}