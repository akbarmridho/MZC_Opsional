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
    int typeValue1stDouble = 0;
    int typeValue2ndDouble = 0;
    int typeValue3rdDouble = 0;
    for (int i = 12; i >= 0; i--)
    {
        if (cardBag[i].first >= 2)
        {
            counter++;
            int cardNum = i + 1;
            int typeValue = cardBag[i].second;

            this->comboValue = (this->comboValue * 100) + cardNum;

            if (counter == 1)
            {
                typeValue1stDouble = typeValue;
            }
            else if (counter == 2)
            {
                typeValue2ndDouble = typeValue;
            }
            else if (counter == 3)
            {
                typeValue3rdDouble = typeValue;
                break;
            }
        }
    }
    int doubleCount = counter;
    while (counter < 3)
    {
        counter++;
        this->comboValue *= 100;
    }
    this->comboValue = (this->comboValue *= 100) + typeValue1stDouble;
    this->comboValue = (this->comboValue *= 100) + typeValue2ndDouble;
    this->comboValue = (this->comboValue *= 100) + typeValue3rdDouble;

    if ((doubleCount <= 1))
    {
        this->comboValue = 0;
    }
}