#ifndef GAMEDECKCANGKUL_HPP
#define GAMEDECKCANGKUL_HPP

#include "../card/CardCangkul.hpp"
#include "../../base/deck/GameDeck.hpp"

class GameDeckCangkul : public GameDeck<CardCangkul>
{
public:
    void shuffle() override;
    void shuffle(vector<CardCangkul> &);

    void fromFile(const string &) override;
};

#endif
