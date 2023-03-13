#ifndef GAMEDECKCANGKUL_HPP
#define GAMEDECKCANGKUL_HPP

#include "../card/CardCangkul.hpp"
#include "../../base/deck/GameDeck.hpp"

class GameDeckCangkul : virtual public GameDeck<CardCangkul> {
public:
    void shuffle() override;

    void fromFile(const string &) override;
};


#endif
