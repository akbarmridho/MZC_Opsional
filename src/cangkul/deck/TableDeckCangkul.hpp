#ifndef TABLEDECKCANGKUL_HPP
#define TABLEDECKCANGKUL_HPP

#include "../card/CardCangkul.hpp"
#include "../player/PlayerCangkul.hpp"
#include <utility>
#include "../../base/deck/TableDeck.hpp"
#include <iostream>

using std::ostream;

class TableDeckCangkul : virtual public TableDeck<pair<PlayerCangkul *, CardCangkul>> {
private:
    CardCangkulType currentType;
    vector<CardCangkul> waste;

public:
    TableDeckCangkul();

    CardCangkulType getCurrentType() const;

    vector<PlayerCangkul *> resolveCards();

    vector<CardCangkul> getWaste();

    int getWasteCount() const;

    void clearWaste();

    void printTable();
};

#endif
