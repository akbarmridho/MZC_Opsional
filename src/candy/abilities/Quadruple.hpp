#include "AbilityCard.hpp"

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

class Quadruple : public virtual AbilityCard {
private:
public:
    /**
     * @brief Construct a new Quadruple object
     *
     */
    Quadruple(GameEngine *ge);

    /**
     * @brief Use the Quadruple ability
     *
     */
    void use();
};

#endif