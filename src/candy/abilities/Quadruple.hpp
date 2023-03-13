#include "AbilityCard.hpp"

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "../game-engine/PointManager.hpp"

class Quadruple : public virtual AbilityCard {
private:
    PointManager *pointManager;

public:
    /**
     * @brief Construct a new Quadruple object
     *
     */
    explicit Quadruple(PointManager *pm);

    /**
     * @brief Use the Quadruple ability
     *
     */
    void use() override;
};

#endif