#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "AbilityCard.hpp"

class Switch : public virtual AbilityCard {
private:
    PlayerCandy **players;

public:
    /**
     * @brief Construct a new Switch object
     *
     */
    explicit Switch(PlayerCandy **);

    /**
     * @brief Use the Switch ability :
     * menukar 2 kartu main deck milik diri sendiri dengan 2 kartu main deck milik pemain lain. Harus bertukar milik sendiri dengan pemain lain. Tidak boleh ke 2 pemain lain.
     *
     */
    void use() override;

    ~Switch() override;
};

#endif