#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../game-engine/GameEngine.hpp"

class AbilityCard {
private:
    bool used;
    bool deactivated;
    string name;
    PlayerCandy *owner;

public:
    AbilityCard(string name);

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

    PlayerCandy *getOwner();

    void deactivate();

    void setUsed();

    void notUsedOrThrow() const;

    void activeOrThrow() const;
};

#endif