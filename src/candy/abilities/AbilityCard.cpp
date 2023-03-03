#include "AbilityCard.hpp"

#include <utility>

AbilityCard::AbilityCard(string name, GameEngine*gameEngine) : name(std::move(name)), used(false) {
    this->gameEngine = gameEngine;
    this->owner = nullptr;
}

bool AbilityCard::getUsed() const {
    return used;
}

string AbilityCard::getName() const {
    return name;
}

void AbilityCard::setOwner(PlayerCandy *player) {
    this->owner = player;
}