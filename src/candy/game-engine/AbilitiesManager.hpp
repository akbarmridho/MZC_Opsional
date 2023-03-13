#ifndef ABILITIESMANAGER_HPP
#define ABILITIESMANAGER_HPP

#include "../player/PlayerCandy.hpp"
#include "../abilities/AbilityCard.hpp"
#include "DeckManager.hpp"
#include "PointManager.hpp"
#include "RoundManager.hpp"
#include <map>

class AbilitiesManager {
public:
    AbilitiesManager();

    AbilitiesManager(PlayerCandy **, DeckManager *, PointManager *, RoundManager *);

    ~AbilitiesManager();

    void shuffle();

    void useAbility(PlayerCandy *);

    void resetAbilities();

protected:
    PlayerCandy **players;
    map<string, AbilityCard *> abilityOwner;
    DeckManager *deckManager;
    PointManager *pointManager;
    RoundManager *roundManager;
};

#endif