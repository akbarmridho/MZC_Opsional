#ifndef ABILITIESMANAGER_HPP
#define ABILITIESMANAGER_HPP

#include "../player/PlayerCandy.hpp"

class AbilitiesManager {
public:
    AbilitiesManager(GameEngine *, PlayerCandy *[]);

    void shuffle();

protected:
    PlayerCandy *players[7];
    GameEngine *gameEngine;
};

#endif