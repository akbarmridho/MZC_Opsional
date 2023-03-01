#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../game-engine/GameEngine.hpp"

class AbilityCard
{
private:
    bool used;
    string name;
    PlayerCandy &owner;

protected:
    GameEngine &gameEngine;

public:
    /**
     * @brief Construct a new Ability Card object
     *
     */
    AbilityCard(GameEngine &);

    /**
     * @brief Virtual function for ability
     *
     */
    virtual void use() = 0;

    bool getUsed() const;

    string getName() const;

    void setOwner(PlayerCandy &);
};

#endif