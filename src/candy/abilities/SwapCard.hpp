#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public virtual AbilityCard
{
private:
public:
    /**
     * @brief Construct a new SwapCard object
     *
     */
    SwapCard(GameEngine *);

    /**
     * @brief Use the SwapCard ability
     *
     */
    void use();
};

#endif