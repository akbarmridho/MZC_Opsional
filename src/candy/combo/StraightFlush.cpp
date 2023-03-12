#include "StraightFlush.hpp"

using std::make_pair;

StraightFlush::StraightFlush(const vector<CardCandy> &cards)
    : Comboable(9, 0)
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

    int prevTypeValue = 15;
    int counter = 0;
    for (int i = 12; i >= 0; i--)
    {
        const pair<int, int> &card = cardBag[i];

        if (prevTypeValue & card.second == 0)
        {
            this->comboValue = card.first;
            this->comboValue = this->comboValue * 100 + card.second;
            counter = 1;
            prevTypeValue = card.second;
        }
        else 
        {
            counter++;
            if (counter == 5) {break;}
            prevTypeValue = prevTypeValue & card.second;
        }
    }
    if (counter <= 4)
    {
        this->comboValue = 0;
    }
}