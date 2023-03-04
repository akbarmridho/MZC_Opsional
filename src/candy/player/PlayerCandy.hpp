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

class PlayerCandy : virtual public Player
{
private:
    PlayerDeckCandy deck;
    AbilityCard *ability;

public:
    PlayerCandy();
    PlayerCandy(string);
    ~PlayerCandy(); // hapus ability
    void receiveCard(CardCandy);

    void receiveAbility(AbilityCard *); // pangil setOwner, hapus ability lama
    AbilityCard *getAbility() const;

    PlayerDeckCandy &getDeck();

    // boolean isFirstRound
    PlayerAction getThenRunAction(bool);
    bool operator>(const Player &);
    bool operator>=(const Player &);
    bool operator<(const Player &);
    bool operator<=(const Player &);
    bool operator==(const Player &);
};

#endif