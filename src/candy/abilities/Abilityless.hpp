#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "AbilityCard.hpp"

class Abilityless : public virtual AbilityCard
{
private:
public:
    /**
     * @brief Construct a new Abilityless object
     *
     */
    Abilityless();

    /**
     * @brief Use the Abilityless ability
     *
     */
    void use(GameEngine &ge);
};

#endif