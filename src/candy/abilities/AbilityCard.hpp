#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../game-engine/GameEngine.hpp"

class AbilityCard
{
private:
    bool used;
    bool deactivated;
    string name;
    PlayerCandy *owner;

protected:
    GameEngine *gameEngine;

public:
    AbilityCard(string name, GameEngine*gameEngine);

    /**
     * @brief Virtual function for ability
     *
     * Caller (dalam hal ini PlayerCandy)
     * harus memastikan kalau kartu belum dipakai dan tidak dinonaktifkan sebelum
     * menggunakan fungsi use
     *
     */
    virtual void use() = 0;

    [[nodiscard]] bool getUsed() const;

    [[nodiscard]] bool isDeactivated() const;

    [[nodiscard]] string getName() const;

    void setOwner(PlayerCandy *);
    PlayerCandy* getOwner();
    void deactivate();
    void setUsed();
};

#endif