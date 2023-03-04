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
    TableDeckCandy *tableDeck;

public:
    PlayerCandy();
    PlayerCandy(string);
    ~PlayerCandy(); // hapus ability
    void receiveCard(CardCandy);

    void receiveAbility(AbilityCard *); // pangil setOwner, hapus ability lama
    AbilityCard *getAbility() const;

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