#ifndef REROLL_HPP
#define REROLL_HPP

#include "AbilityCard.hpp"

class Reroll : public virtual AbilityCard
{
private:
public:
    /**
     * @brief Construct a new Reroll object
     *
     */
    Reroll();

    /**
     * @brief Use the Reroll ability
     *
     */
    void use(GameEngine &ge);
};

#endif