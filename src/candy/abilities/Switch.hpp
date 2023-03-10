#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "AbilityCard.hpp"

class Switch : public virtual AbilityCard {
private:
public:
    /**
     * @brief Construct a new Switch object
     *
     */
    Switch(GameEngine *ge);

    /**
     * @brief Use the Switch ability
     *
     */
    void use();
};

#endif