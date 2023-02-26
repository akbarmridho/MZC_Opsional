#ifndef PLAYERDECKCANDY_HPP
#define PLAYERDECKCANDY_HPP

#include "../../base/deck/PlayerDeck.hpp"
#include "../card/CardCandy.hpp"
#include "./TableDeckCandy.hpp"

class PlayerDeckCandy : virtual public PlayerDeck<CardCandy>
{
public:
    void resetDeck();
    double combo(TableDeckCandy &);
};
#endif