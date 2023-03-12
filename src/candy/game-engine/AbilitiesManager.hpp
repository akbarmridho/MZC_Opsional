#ifndef ABILITIESMANAGER_HPP
#define ABILITIESMANAGER_HPP

#include "../player/PlayerCandy.hpp"
#include "DeckManager.hpp"
#include "PointManager.hpp"
#include "RoundManager.hpp"

class AbilitiesManager
{
public:
    AbilitiesManager();

    AbilitiesManager(PlayerCandy **, DeckManager *, PointManager *, RoundManager *);

    void shuffle();

protected:
    PlayerCandy *players[7];
    DeckManager *deckManager;
    PointManager *pointManager;
    RoundManager *roundManager;
};

#endif