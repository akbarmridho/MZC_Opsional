#include "CardCangkul.hpp"
#include "../../utils/interface.hpp"

using std::to_string;

value_pair_t CardCangkul::value() const
{
    return value_pair_t{this->type, this->number};
}

std::string CardCangkul::getTypeString() const
{
    return typeToString(this->type);
}

CardCangkul::CardCangkul(CardCangkulType type, int value) : Card(type, value)
{
}

string CardCangkul::getNumberReps()
{
    if (this->number >= 1 && this->number <= 9)
    {
        return to_string(this->number + 1);
    }
    else if (this->number == 10)
    {
        return "J";
    }
    else if (this->number == 11)
    {
        return "Q";
    }
    else if (this->number == 12)
    {
        return "K";
    }
    else
    {
        return "A";
    }
}

std::string typeToString(CardCangkulType type)
{
    if (type == spade)
    {
        return "♠";
        // return "Sekop";
    }
    else if (type == heart)
    {
        return "♥";
        // return "Hati";
    }
    else if (type == diamond)
    {
        // return "Wajik";
        return "♦";
    }

    // return "Keriting";
    return "♣";
}

std::ostream &operator<<(std::ostream &stream, CardCangkul &c)
{
    return stream << getTypeColor(c.type) << c.getTypeString() << c.getNumberReps() << reset();
}

string getTypeColor(CardCangkulType type)
{
    switch (type)
    {
    case spade:
    case club:
        return cblue();
    default:
        return cred();
    }
}

std::ostream &operator<<(std::ostream &stream, CardCangkulType type)
{
    return stream << getTypeColor(type) << typeToString(type) << reset();
}