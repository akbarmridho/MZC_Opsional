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

using std::vector;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

AbilitiesManager::AbilitiesManager() {
}

AbilitiesManager::AbilitiesManager(PlayerCandy **players, DeckManager *dm, PointManager *pm, RoundManager *rm) {
    for (int i = 0; i < 7; i++) {
        this->players[i] = players[i];
    }

    this->deckManager = dm;
    this->pointManager = pm;
    this->roundManager = rm;
}

void AbilitiesManager::shuffle() {
    vector<AbilityCard *> options;
    options.push_back((AbilityCard *) new Abilityless(this->gameEngine));
    options.push_back((AbilityCard *) new Quarter(this->gameEngine));
    options.push_back((AbilityCard *) new Quadruple(this->gameEngine));
    options.push_back((AbilityCard *) new Reroll(this->gameEngine));
    options.push_back((AbilityCard *) new Reverse(this->gameEngine));
    options.push_back((AbilityCard *) new SwapCard(this->players));
    options.push_back((AbilityCard *) new Switch(this->gameEngine));

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distributor(0, 6);

    for (auto &player: this->players) {
        int idx = distributor(generator) % (int) options.size();
        player->receiveAbility(options[idx]);
        options.erase(options.begin() + idx, options.begin() + idx);
    }
}