#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "../../base/player/Player.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../abilities/AbilityStatus.hpp"

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
    AbilityStatus *abilityStatus;
    TableDeckCandy *tableDeck;

public:
    PlayerCandy();
    PlayerCandy(string);
    ~PlayerCandy(); // hapus ability
    void receiveCard(CardCandy);

    void receiveAbility(AbilityStatus *); // pangil setOwner, hapus ability lama
    AbilityStatus *getAbility() const;

    PlayerDeckCandy &getDeck() const;
    void updateTableDeck(TableDeckCandy *);

    // boolean isFirstRound
    PlayerAction getThenRunAction(bool);
    bool operator>(const Player &) const;
    bool operator>=(const Player &) const;
    bool operator<(const Player &) const;
    bool operator<=(const Player &) const;
    bool operator==(const Player &) const;
};

#endif