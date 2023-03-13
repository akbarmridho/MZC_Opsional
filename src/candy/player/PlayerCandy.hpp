#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "../../base/player/Player.hpp"
#include "../deck/PlayerDeckCandy.hpp"
#include "../abilities/AbilityStatus.hpp"
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
    AbilityStatus *abilityStatus;
    TableDeckCandy *tableDeck;

public:
    PlayerCandy();
    PlayerCandy(string);
    ~PlayerCandy();
    void receiveCard(CardCandy);

    void receiveAbility(AbilityStatus *); // setowner di manager
    AbilityStatus *getAbility() const;

    PlayerDeckCandy &getDeck();
    void updateTableDeck(TableDeckCandy *);

    // boolean isFirstRound
    PlayerAction getThenRunAction(bool);
    bool operator>(PlayerCandy &);
    bool operator<(PlayerCandy &);
    bool operator==(PlayerCandy &);
};

#endif