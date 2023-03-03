#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "AbilityCard.hpp"

class Reverse : public virtual AbilityCard
{
private:
public:
    /**
     * @brief Construct a new Reverse object
     *
     */
    Reverse(GameEngine &ge);

    /**
     * @brief Use the Reverse ability
     *
     */
    void use();
};

#endif