#ifndef CARDCANDY_HPP
#define CARDCANDY_HPP
#include "../../base/card/Card.hpp"
#include <string>

enum CardCandyType
{
    green,
    blue,
    yellow,
    red
};

class CardCandy : virtual public Card<CardCandyType>
{
    /**
     * @brief Construct a new Card object
     *
     * @param type
     * @param number
     */
    CardCandy(CardCandyType type, int number);

    /**
     * @brief get value of Card
     *
     * @return double
     */
    virtual double value() const;

    bool operator>(const CardCandy &) const;
    bool operator==(const CardCandy &) const;
    bool operator<(const CardCandy &) const;

    std::string getTypeString() const;
};

#endif