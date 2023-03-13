#include "CardCandy.hpp"

CardCandy::CardCandy(CardCandyType type, int number) : Card(type, number)
{
}

value_pair_t CardCandy::value() const
{
    value_pair_t ret = {type, number};
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

bool CardCandy::operator>(const CardCandy &other) const
{
    if (this->type == other.type)
    {
        return this->number > other.number;
    }
    else
    {
        return this->type > other.type;
    }
}
bool CardCandy::operator==(const CardCandy &other) const
{
    return this->type == other.type && this->number == other.number;
}
bool CardCandy::operator<(const CardCandy &other) const
{
    if (this->type == other.type)
    {
        return this->number < other.number;
    }
    else
    {
        return this->type < other.type;
    }
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
    case red:
        return "red";
        break;
    }
}