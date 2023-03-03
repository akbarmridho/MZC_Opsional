#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../game-engine/GameEngine.hpp"

class AbilityCard
{
private:
    bool used;
    string name;
    PlayerCandy *owner;

protected:
    GameEngine *gameEngine;

public:
    AbilityCard(string name, GameEngine*gameEngine);

    /**
     * @brief Virtual function for ability
     *
     */
    virtual void use() = 0;

    [[nodiscard]] bool getUsed() const;

    [[nodiscard]] string getName() const;

    void setOwner(PlayerCandy *);
};

#endif