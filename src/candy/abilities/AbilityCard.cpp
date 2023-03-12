#include "AbilityCard.hpp"

#include <utility>

AbilityCard::AbilityCard(string name) : status(name)
{
    this->owner = nullptr;
}

AbilityStatus &AbilityCard::getStatus()
{
    return status;
};

void AbilityCard::setOwner(PlayerCandy *player)
{
    this->owner = player;
}

PlayerCandy *AbilityCard::getOwner()
{
    return this->owner;
}
