#include "AbilityCard.hpp"

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

class Quadruple : public virtual AbilityCard
{
private:
    PointManager *pointManager;

public:
    /**
     * @brief Construct a new Quadruple object
     *
     */
    Quadruple(PointManager *pm);

    /**
     * @brief Use the Quadruple ability
     *
     */
    void use();
};

#endif