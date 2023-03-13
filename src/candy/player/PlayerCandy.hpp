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
    half,
    status,
};

class PlayerCandy : public Player
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
    PlayerAction getAction(bool);

    bool operator>(PlayerCandy &);

    bool operator<(PlayerCandy &);

    bool operator==(PlayerCandy &);

    void showStatus(bool);
};

#endif