#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "../../base/player/Player.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../abilities/AbilityCard.hpp"

class CandyPlayer : public Player
{
private:
    PlayerDeckCandy deck;
    AbilityCard &ability;

public:
};

#endif