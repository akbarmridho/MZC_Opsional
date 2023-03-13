#include "PlayerDeckCangkul.hpp"

CardCangkul PlayerDeckCangkul::popAt(int idx)
{
    CardCangkul card = this->cards[idx];
    this->cards.erase(this->cards.begin() + 1);

    return card;
}