#ifndef PLAYERCANGKUL_HPP
#define PLAYERCANGKUL_HPP

#include "../../base/player/Player.hpp"
#include "../card/CardCangkul.hpp"
#include "../deck/PlayerDeckCangkul.hpp"

class PlayerCangkul : public Player
{
public:
    PlayerCangkul(string name);

    CardCangkul selectCard();

    CardCangkul selectCardWithType(CardCangkulType);

    int countCardWithType(CardCangkulType);

    void receiveCard(CardCangkul);

    PlayerDeckCangkul deck;
};

#endif
