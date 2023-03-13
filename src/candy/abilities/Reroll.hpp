#ifndef REROLL_HPP
#define REROLL_HPP

#include "AbilityCard.hpp"
#include "../game-engine/DeckManager.hpp"

class Reroll : public virtual AbilityCard {
private:
    DeckManager *deckManager;

public:
    /**
     * @brief Construct a new Reroll object
     *
     */
    explicit Reroll(DeckManager *);

    /**
     * @brief Use the Reroll ability :
     * membuang 2 kartu dari main deck yang dimiliki oleh diri sendiri dan mengambil ulang 2 kartu.
     *
     */
    void use() override;
};

#endif