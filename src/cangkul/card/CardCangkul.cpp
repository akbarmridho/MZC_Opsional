#include "CardCangkul.hpp"

value_pair_t CardCangkul::value() const {
    return value_pair_t{this->type, this->number};
}

std::string CardCangkul::getTypeString() const {
    if (this->type == spade) {
        return "Sekop";
    } else if (this->type == heart) {
        return "Hati";
    } else if (this->type == diamond) {
        return "Wajik";
    }

    return "Keriting";
}

CardCangkul::CardCangkul(CardCangkulType type, int value) : Card(type, value) {

}
