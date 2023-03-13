#include "Flush.hpp"
#include <algorithm>


Flush::Flush(const vector<CardCandy> &cards)
    : Comboable(6, 0)
{
    computeCombo(cards);
}

void Flush::computeCombo(vector<CardCandy> cards) // copy so that cards can be sorted freely
{

    // sort by value
    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         { return a > b; });

    vector<int> countType = vector<int>(4, 0);

    for (int i = 0; i < cards.size(); i++)
    {
        const CardCandy &card = cards[i];
        countType[card.getType()]++;
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
        int counter = 0;
        for (int i=0; i <= cards.size(); i++)
        {
            const CardCandy &card = cards[i];
            if (card.getType() == typeGreaterThanFive)
            {
                this->comboValue = this->comboValue * 100 + card.getNumber();
                this->comboValue = this->comboValue * 10 + card.getType();
                counter++;

                if (counter == 5)
                {
                    break;
                }
            }
        }
    }

}