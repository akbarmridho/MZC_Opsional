#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public virtual AbilityCard
{
private:
    PlayerCandy *players[7];

public:
    /**
     * @brief Construct a new SwapCard object
     *
     */
    explicit SwapCard(PlayerCandy *[7]);

    /**
     * @brief Use the SwapCard ability
     *
     */
    void use();
};

#endif