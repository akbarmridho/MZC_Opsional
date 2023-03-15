#include "Straight.hpp"
#include <iostream>
#include <algorithm>
#include "../../utils/max.hpp"

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
    int i = 12;
    for (i; i >= 0; i--)
    {
        if (cardBag[i].first == 0)
        {
            if (counter >= 5)
            {
                break;
            }
            else
            {
                counter = 1;
            }
        }
        else
        {
            counter++;
        }
    }
    if (counter >= 5)
    {
        int index_end = i + 1;
        for (i = index_end + counter - 1; i >= index_end; i--)
        {
            this->comboValue = (this->comboValue << 4) + (i + 1);
            this->comboValue = (this->comboValue << 4) + cardBag[i].second;
        }
        while (counter < 7)
        {
            counter++;
            this->comboValue <<= 8;
        } 
    }
    

}