#ifndef GAMEDECKCANDY_HPP
#define GAMEDECKCANDY_HPP

#include "../../base/deck/GameDeck.hpp"
#include "../card/CardCandy.hpp"
class GameDeckCandy : virtual public GameDeck<CardCandy>
{
public:
//    void resetDeck(); panggil method reset dari base class InventoryHolder

protected:
    void shuffle() override;
    void fromFile(const string&) override;
};
#endif