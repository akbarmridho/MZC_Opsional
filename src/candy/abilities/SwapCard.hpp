#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public virtual AbilityCard {
private:
    PlayerCandy **players;

public:
    /**
     * @brief Construct a new SwapCard object
     *
     */
    explicit SwapCard(PlayerCandy **);

    ~SwapCard() override;

    /**
     * @brief Use the SwapCard ability
     *
     */
    void use() override;
};

#endif