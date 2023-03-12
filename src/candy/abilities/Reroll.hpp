#ifndef REROLL_HPP
#define REROLL_HPP

#include "AbilityCard.hpp"

class Reroll : public virtual AbilityCard
{
private:
    GameDeckCandy *gamedeck;

public:
    /**
     * @brief Construct a new Reroll object
     *
     */
    Reroll(GameDeckCandy *);

    /**
     * @brief Use the Reroll ability :
     * membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.
     *
     */
    void use();
};

#endif