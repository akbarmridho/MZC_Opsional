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

    int prevTypeValue = 0;
    int counter = 0;
    for (int i = 12; i >= 0; i--)
    {
        const pair<int, int> &card = cardBag[i];

        if ((prevTypeValue & card.second) == 0)
        {
            if (counter >= 5)
            {
                break;
            }
            else
            {
                this->comboValue = i + 1;
                counter = 1;
                prevTypeValue = card.second;
            }
        }
        else 
        {
            prevTypeValue = prevTypeValue & card.second;
            counter++;
            switch (counter)
            {
            case 5:
                this->comboValue = this->comboValue * 100 + prevTypeValue;
                break;
            
            case 6:
                this->comboValue = this->comboValue * 100 + i + 5;
                break;

            case 7:
                this->comboValue = this->comboValue * 100 + i + 5;
                break;

            default:
                break;
            }

            if (counter == 7) {break;}
        }
    }
    if (counter >= 5)
    {
        while(counter < 7)
        {
            counter++;
            this->comboValue *= 100;
        } 
    } else {
        this->comboValue = 0;
    }
}