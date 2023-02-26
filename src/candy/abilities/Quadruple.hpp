#include "AbilityCard.hpp"

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

class Quadruple : public AbilityCard
{
private:
public:
    /**
     * @brief Construct a new Quadruple object
     *
     */
    Quadruple();

    void use(GameEngine &ge);
};

#endif