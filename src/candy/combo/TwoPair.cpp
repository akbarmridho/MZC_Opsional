#include "TwoPair.hpp"
#include <iostream>
#include <math.h>

using std::pair;
using std::make_pair;
using std::vector;

TwoPair::TwoPair(const vector<CardCandy> &cards)
    : Comboable(2, 0)
{
    int highCardNum, highTypeValue;
    int lowCardNum, lowTypeValue;


    using VectorPair = vector<pair<int, int>>;
    VectorPair cardBag(13, make_pair(0,0));

    for (const auto card : cards)
    {
        int cardNum = card.getNumber();
        int typeValue = 1<<card.getType();
        cardBag[cardNum - 1].first++;
        cardBag[cardNum - 1].second += typeValue;
    }
    
    int i = 12;
    for (i; i >= 0; i--)
    {
        if (cardBag[i].first >= 2)
        {
            highCardNum = i + 1;
            highTypeValue = cardBag[i].second;
            break;
        }
    }

    bool found = false;
    int j = i - 1;
    for (j; j >= 0; j--)
    {
        if (cardBag[j].first >= 2)
        {
            found = true;
            lowCardNum = j + 1;
            lowTypeValue = cardBag[j].second;
            break;
        }
    }

    if (found)
    {
        this->comboValue += highCardNum * pow(10, 6);
        this->comboValue += highTypeValue * pow(10, 4);
        this->comboValue += lowCardNum * pow(10, 2);
        this->comboValue += lowTypeValue * pow(10, 0);

    }
}