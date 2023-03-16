#include "CardCandy.hpp"
#include "../../utils/interface.hpp"
#include <iostream>

using std::cout;

CardCandy::CardCandy(CardCandyType type, int number) : Card(type, number)
{
}

value_pair_t CardCandy::value() const
{
    value_pair_t ret = {number, type};
    return ret;
}

CardCandyType CardCandy::getType() const
{
    return type;
}

int CardCandy::getNumber() const
{
    return number;
}

string CardCandy::getTypeString() const
{
    switch (this->type)
    {
    case green:
        return "green";
        break;
    case blue:
        return "blue";
        break;
    case yellow:
        return "yellow";
        break;
    default:
        return "red";
        break;
    }
}

string CardCandy::getTypeColor() const
{
    switch (this->type)
    {
    case green:
        return cgreen();
        break;
    case blue:
        return cblue();
        break;
    case yellow:
        return cyellow();
        break;
    default:
        return cred();
        break;
    }
}

std::ostream &operator<<(std::ostream &stream, CardCandy &c) {
    return stream << c.getTypeColor() << c.getNumber() << " " << c.getTypeString() << reset();;
}