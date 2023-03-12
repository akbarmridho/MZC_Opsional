#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "AbilityCard.hpp"

class Reverse : public virtual AbilityCard {
private:
    RoundManager *roundManager;
public:
    /**
     * @brief Construct a new Reverse object
     *
     */
    Reverse(RoundManager *rm);

    /**
     * @brief Use the Reverse ability
     *
     */
    void use();
};

#endif