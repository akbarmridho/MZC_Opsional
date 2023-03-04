#ifndef ABILITIESMANAGER_HPP
#define ABILITIESMANAGER_HPP

#include "../player/PlayerCandy.hpp"

class AbilitiesManager
{
public:
    AbilitiesManager();
    AbilitiesManager(GameEngine *, PlayerCandy *[7]);

    void shuffle();

protected:
    PlayerCandy *players[7];
    GameEngine *gameEngine;
};

#endif