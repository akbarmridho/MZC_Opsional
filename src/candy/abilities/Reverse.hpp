#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "AbilityCard.hpp"
#include "../game-engine/RoundManager.hpp"

class Reverse : public virtual AbilityCard {
private:
    RoundManager *roundManager;
public:
    /**
     * @brief Construct a new Reverse object
     *
     */
    explicit Reverse(RoundManager *rm);

    /**
     * @brief Use the Reverse ability
     *
     */
    void use() override;
};

#endif