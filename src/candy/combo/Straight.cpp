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
        try
        {
        cardBag[cardNum - 1].second = std::max<int>(cardBag[cardNum - 1].second, typeValue);
        }
        catch (NoMaxException &e)
        {
            cout << "Terdapat nilai yang sama pada perbandingan fungsi straight" << endl;
        }
    }

    int count = 0;
    int i = 12;
    for (i; i > 0; i--)
    {
        if (cardBag[i].first == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            if (count == 5) {break;}
        }
    }
    if (count == 5)
    {
        int index_end = i;
        for (i = index_end + 4; i >= index_end; i--)
        {
            this->comboValue = this->comboValue * 100 + (i + 1);
            this->comboValue = this->comboValue * 10 + cardBag[i].second;
        }
    }
    

}