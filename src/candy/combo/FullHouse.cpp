#include "FullHouse.hpp"
#include <iostream>

using std::pair;
using std::make_pair;
using std::vector;

FullHouse::FullHouse(const vector<CardCandy> &cards)
    : Comboable(7, 0)
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
        if (cardBag[i].first >= 3)
        {
            counter++;
            int cardNum = i + 1;
            int typeValue = cardBag[i].second;

            this->comboValue = (this->comboValue << 4) + cardNum;
            this->comboValue = (this->comboValue << 4) + typeValue;

            if (counter == 2)
            {
                break;
            }
        }
    }
    int tripleCount = counter;
    while (counter < 2)
    {
        counter++;
        this->comboValue <<= 8;
    }

    counter = 0;
    for (int i = 12; i >= 0; i--)
    {
        if (cardBag[i].first >= 2)
        {
            counter++;
            int cardNum = i + 1;
            int typeValue = cardBag[i].second;

            this->comboValue = (this->comboValue << 4) + cardNum;
            this->comboValue = (this->comboValue << 4) + typeValue;

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
        this->comboValue <<= 8;
    }

    if ((tripleCount == 0) || (doubleCount <= 1))
    {
        this->comboValue = 0;
    }
}