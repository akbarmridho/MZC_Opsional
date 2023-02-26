#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../game-engine/GameEngine.hpp"

class AbilityCard
{
private:
    bool used;

public:
    /**
     * @brief Construct a new Ability Card object
     *
     */
    AbilityCard();

    /**
     * @brief Virtual function for ability
     *
     */
    virtual void use(GameEngine &) = 0;

    /**
     * @brief Function to toggle card is used or not
     *
     */
    void toggleUsed();
};

#endif