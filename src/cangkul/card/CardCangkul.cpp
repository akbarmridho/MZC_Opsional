#include "CardCangkul.hpp"

using std::to_string;

value_pair_t CardCangkul::value() const
{
    return value_pair_t{this->type, this->number};
}

std::string CardCangkul::getTypeString() const
{
    if (this->type == spade)
    {
        return "♠";
        // return "Sekop";
    }
    else if (this->type == heart)
    {
        return "♥";
        // return "Hati";
    }
    else if (this->type == diamond)
    {
        // return "Wajik";
        return "♦";
    }

    // return "Keriting";
    return "♣";
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
