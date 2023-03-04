#ifndef CARDCANDY_HPP
#define CARDCANDY_HPP
#include "../../base/card/Card.hpp"
#include <string>

using std::string;

enum CardCandyType
{
    green = 0,
    blue = 1,
    yellow = 2,
    red = 3
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
    double value() const;

    bool operator>(const CardCandy &) const;
    bool operator==(const CardCandy &) const;
    bool operator<(const CardCandy &) const;

    string getTypeString() const;
};

#endif