#include "StraightFlush.hpp"
#include <algorithm>

using std::make_pair;

StraightFlush::StraightFlush(const vector<CardCandy> &cards)
    : Comboable(9, 0)
{
    computeCombo(cards);
}

void StraightFlush::computeCombo(vector<CardCandy> cards) // copy so that cards can be sorted freely
{
    using VectorPair = vector<pair<int, int>>;
    VectorPair cardBag(13, make_pair(0,0));

    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         { return a > b; });

    vector<int> countType = vector<int>(4, 0);

    for (int i = 0; i < cards.size(); i++)
    {
        countType[cards[i].getType()]++;
    }

    int typeGreaterThanFive = -1;
    for (int i = 0; i <= 3; i++)
    {
        if (countType[i] >= 5)
        {
            typeGreaterThanFive = i;
            break;
        } 
    }

    if (typeGreaterThanFive != -1)
    {
        for (const auto card : cards)
        {
            int cardNum = card.getNumber();
            int typeValue = card.getType();
            if (typeValue == typeGreaterThanFive)
            {
                cardBag[cardNum - 1].first++;
                cardBag[cardNum - 1].second += typeValue;
            }
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
                    this->comboValue = this->comboValue * 100 + (currentNum);
                }
                else
                {
                     if (counter >= 5)
                    {
                        break;
                    }
                    else
                    {
                        counter = 1;
                        this->comboValue = (currentNum);
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
                this->comboValue *= 100;
            }
            this->comboValue = this->comboValue * 10 + typeGreaterThanFive;
        }
        else
        {
            this->comboValue = 0;
        }
        
        
    }
}