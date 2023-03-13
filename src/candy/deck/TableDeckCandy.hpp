#ifndef TABLEDECKCANDY_HPP
#define TABLEDECKCANDY_HPP

#include "../../base/deck/TableDeck.hpp"
#include "../card/CardCandy.hpp"
class TableDeckCandy : virtual public TableDeck<CardCandy>
{
public:
    void resetDeck();
};
#endif