#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "AbilityCard.hpp"

class Abilityless : public virtual AbilityCard
{
private:
    PlayerCandy *players[7];

public:
    /**
     * @brief Construct a new Abilityless object
     *
     */
    Abilityless(PlayerCandy *[7]);

    /**
     * @brief Use the Abilityless ability
     *
     */
    void use();
};

#endif