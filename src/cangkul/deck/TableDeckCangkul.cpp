#include "TableDeckCangkul.hpp"

#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::sort;

TableDeckCangkul::TableDeckCangkul()
{
}

CardCangkulType TableDeckCangkul::getCurrentType() const
{
    return this->cards[0].second.getType();
}

vector<PlayerCangkul *> TableDeckCangkul::resolveCards()
{
    vector<PlayerCangkul *> ranks;

    sort(this->cards.begin(), this->cards.end(),
         [](pair<PlayerCangkul *, CardCangkul> &c1, pair<PlayerCangkul *, CardCangkul> &c2)
         {
             return c1.second.getNumber() > c2.second.getNumber();
         });

    for (auto &card : cards)
    {
        ranks.push_back(card.first);
        this->waste.push_back(card.second);
    }

    this->cards.clear();

    return ranks;
}

vector<CardCangkul> TableDeckCangkul::getWaste()
{
    return this->waste;
}

void TableDeckCangkul::clearWaste()
{
    this->waste.clear();
}

void TableDeckCangkul::printTable()
{
    cout << "Table deck: ";

    if (cards.empty())
    {
        cout << "kosong";
    }

    for (auto &cpair : cards)
    {
        cout << cpair.second.getTypeString() << "-" << cpair.second.getNumberReps() << " ";
    }

    cout << endl;
}