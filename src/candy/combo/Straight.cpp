#include "Straight.hpp"
#include <iostream>
#include <algorithm>

using std::make_pair;
using std::cout;
using std::endl;

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
        cardBag[cardNum - 1].second += typeValue;
    }
    int counter = 0;
    int prevNum = 14;
    for (int i=cardBag.size() - 1; i >= 0; i--)
    {
        const pair<int, int> &card = cardBag[i];
        if (card.first >= 1)
        {
            int currentNum = (i + 1);
            if (currentNum + 1 == prevNum)
            {
                counter++;
                this->comboValue = (this->comboValue<<4) + (currentNum);
                this->comboValue = (this->comboValue<<4) + card.second;
            }
            else
            {
                if (counter >= 5) {break;}
                else
                {
                    counter = 1;
                    this->comboValue = (currentNum);
                    this->comboValue = (this->comboValue<<4) + card.second;
                }
            }
            prevNum = currentNum;
        }
    }
    if (counter >= 5)
    {
        while (counter < 7)
        {
            counter++;
            this->comboValue <<= 8;
        }
    }
    else
    {
        this->comboValue = 0;
    }
}