#include "AbilitiesManager.hpp"
#include "../abilities/Abilityless.hpp"
#include "../abilities/Quadruple.hpp"
#include "../abilities/Quarter.hpp"
#include "../abilities/Reroll.hpp"
#include "../abilities/Reverse.hpp"
#include "../abilities/SwapCard.hpp"
#include "../abilities/Switch.hpp"
#include <random>
#include <vector>
#include <algorithm>

using std::vector;

AbilitiesManager::AbilitiesManager() {
    this->players = nullptr;
    this->deckManager = nullptr;
    this->pointManager = nullptr;
    this->roundManager = nullptr;
}

AbilitiesManager::AbilitiesManager(PlayerCandy **players, DeckManager *dm, PointManager *pm, RoundManager *rm) {
    this->players = new PlayerCandy *[7];

    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }

    this->deckManager = dm;
    this->pointManager = pm;
    this->roundManager = rm;
}

void AbilitiesManager::shuffle() {
    vector<AbilityCard *> options;
    options.push_back((AbilityCard *) new Abilityless(this->players));
    options.push_back((AbilityCard *) new Quarter(this->pointManager));
    options.push_back((AbilityCard *) new Quadruple(this->pointManager));
    options.push_back((AbilityCard *) new Reroll(this->deckManager));
    options.push_back((AbilityCard *) new Reverse(this->roundManager));
    options.push_back((AbilityCard *) new SwapCard(this->players));
    options.push_back((AbilityCard *) new Switch(this->players));
    std::shuffle(options.begin(), options.end(), std::mt19937(std::random_device()()));

    for (int i = 0; i < 7; i++) {
        players[i]->receiveAbility(&options[i]->getStatus());
        this->abilityOwner.insert({players[i]->getName(), options[i]});
    }
}

void AbilitiesManager::useAbility(PlayerCandy *player) {
    this->abilityOwner[player->getName()]->use();
}

AbilitiesManager::~AbilitiesManager() {
    delete[] this->players;
}

void AbilitiesManager::resetAbilities() {
    for (auto &pair: this->abilityOwner) {
        delete pair.second;
    }
    this->abilityOwner.clear();
}
