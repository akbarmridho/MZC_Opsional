/* Card.hpp*/

#ifndef CARD_HPP
#define CARD_HPP

#include <string.h>

template <class T>
class Card
{
protected:
    const T type;
    const int number;

public:
    /**
     * @brief Virtual function to get value of Card
     *
     * @return double
     */
    virtual double value() const = 0;

    // virtual bool operator>(const Card<T> &) const = 0;
    // virtual bool operator==(const Card<T> &) const = 0;
    // virtual bool operator<(const Card<T> &) const = 0;

    T getType() const;

    virtual std::string getTypeString() const = 0;

    int getNumber() const;
};

#endif