/* Card.hpp */

#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include "Valuable.hpp"

using std::string;

template <class T>
class Card : public Valuable
{
protected:
    T type; // const dihapus karena membuat assignment operator dihapus
    int number; // const dihapus karena membuat assignment operator dihapus

public:
     Card(T type, int number);
     virtual bool operator>(const Card<T> &) const = 0;
     virtual bool operator==(const Card<T> &) const = 0;
     virtual bool operator<(const Card<T> &) const = 0;

    T getType() const;

    [[nodiscard]] virtual std::string getTypeString() const = 0;

    [[nodiscard]] int getNumber() const;
};

#endif