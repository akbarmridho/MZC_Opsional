#ifndef GAMEDECKCANDY_HPP
#define GAMEDECKCANDY_HPP

#include "../../base/deck/GameDeck.hpp"
#include "../card/CardCandy.hpp"

class GameDeckCandy : public GameDeck<CardCandy> {
public:
    void shuffle() override;

    void fromFile(const string &) override;
};

#endif