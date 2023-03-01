/* Card.hpp */

#ifndef CARD_HPP
#define CARD_HPP

#include <string.h>
#include "Valuable.hpp"

template <class T>
class Card : public Valuable
{
protected:
    const T type;
    const int number;

public:
    // virtual bool operator>(const Card<T> &) const = 0;
    // virtual bool operator==(const Card<T> &) const = 0;
    // virtual bool operator<(const Card<T> &) const = 0;

    T getType() const;

    virtual std::string getTypeString() const = 0;

    int getNumber() const;
};

#endif