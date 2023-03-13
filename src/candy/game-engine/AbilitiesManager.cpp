#include "AbilitiesManager.hpp"
#include "../abilities/Abilityless.hpp"
#include "../abilities/Quadruple.hpp"
#include "../abilities/Quarter.hpp"
#include "../abilities/Reroll.hpp"
#include "../abilities/Reverse.hpp"
#include "../abilities/SwapCard.hpp"
#include "../abilities/Switch.hpp"
#include <vector>
#include <random>

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
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

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distributor(0, 6);

    for (int i = 0; i < 7; i++) {
        int idx = distributor(generator) % (int) options.size();
        players[i]->receiveAbility(&options[idx]->getStatus());
        this->abilityOwner.insert({players[i]->getName(), options[idx]});
        options.erase(options.begin() + idx, options.begin() + idx);
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
