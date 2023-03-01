#ifndef ABILITIESMANAGER_HPP
#define ABILITIESMANAGER_HPP

#include "../player/PlayerCandy.hpp"

class AbilitiesManager
{
public:
    void shuffleAbilities();

protected:
    PlayerCandy *players;
};

#endif