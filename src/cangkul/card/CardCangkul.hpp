#ifndef CARDCANGKUL_HPP
#define CARDCANGKUL_HPP

#include "../../base/card/Card.hpp"

enum CardCangkulType
{
    spade = 0,
    heart = 1,
    diamond = 2,
    club = 3
};

class CardCangkul : public Card<CardCangkulType>
{
public:
    CardCangkul(CardCangkulType type, int value);

    [[nodiscard]] value_pair_t value() const override;

    [[nodiscard]] std::string getTypeString() const override;
};

#endif
