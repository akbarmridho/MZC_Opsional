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

class CardCandy : public Card<CardCandyType>
{
public:
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
     * @return value_pair_t
     */
    value_pair_t value() const;

    CardCandyType getType() const;

    int getNumber() const;

    string getTypeString() const;

    string getTypeColor() const;

    friend std::ostream &operator<<(std::ostream &stream, CardCandy &c);
};

#endif