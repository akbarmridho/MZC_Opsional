#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../player/PlayerCandy.hpp"
#include "AbilityStatus.hpp"

class AbilityCard {
private:
    AbilityStatus status;
    PlayerCandy *owner;

public:
    explicit AbilityCard(string name);

    virtual ~AbilityCard();

    /**
     * @brief Virtual function for ability
     *
     * Caller (dalam hal ini PlayerCandy)
     * harus memastikan kalau kartu belum dipakai dan tidak dinonaktifkan sebelum
     * menggunakan fungsi use
     *
     */
    virtual void use() = 0;

    AbilityStatus &getStatus();

    void setOwner(PlayerCandy *);

    PlayerCandy *getOwner();
};

#endif