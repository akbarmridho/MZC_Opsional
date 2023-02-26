#ifndef GAMEDECKCANDY_HPP
#define GAMEDECKCANDY_HPP

#include "../../base/deck/GameDeck.hpp"
#include "../card/CardCandy.hpp"
class GameDeckCandy : virtual public GameDeck<CardCandy>
{
public:
    void resetDeck();

protected:
    void shuffle();
    void from_file();
};
#endif