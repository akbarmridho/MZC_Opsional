#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "../../base/player/Player.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../abilities/AbilityCard.hpp"

const int PLAYER_COUNT = 7;

enum PlayerAction
{
    ability,
    next,
    dbl,
    half
};

class PlayerCandy : public Player
{
private:
    PlayerDeckCandy deck;
    AbilityCard& ability;

public:
    void receiveCard(CardCandy);
    void receiveAbility(AbilityCard); // pangil setOwner
    AbilityCard& getAbility() const;
    PlayerDeckCandy& getDeck();
    PlayerAction getThenRunAction();
};

#endif