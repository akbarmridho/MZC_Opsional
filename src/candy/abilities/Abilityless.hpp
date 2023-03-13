#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "AbilityCard.hpp"

class Abilityless : public virtual AbilityCard {
private:
    PlayerCandy **players;

public:
    /**
     * @brief Construct a new Abilityless object
     *
     */
    explicit Abilityless(PlayerCandy **);

    ~Abilityless() override;

    /**
     * @brief Use the Abilityless ability
     *
     */
    void use() override;
};

#endif