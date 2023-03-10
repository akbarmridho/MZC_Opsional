#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "../../base/player/Player.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../abilities/AbilityCard.hpp"

const int PLAYER_COUNT = 7;

enum PlayerAction {
    ability,
    next,
    dbl,
    half
};

class PlayerCandy : public Player {
private:
    PlayerDeckCandy deck;
    AbilityCard *ability;

public:
    ~PlayerCandy(); // hapus ability
    void receiveCard(CardCandy);

    void receiveAbility(AbilityCard *); // pangil setOwner, hapus ability lama
    AbilityCard *getAbility() const;

    PlayerDeckCandy &getDeck();

    PlayerAction getThenRunAction();
};

#endif