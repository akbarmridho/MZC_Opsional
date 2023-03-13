#include "Card.hpp"
#include "../../candy/card/CardCandy.hpp"
#include "../../cangkul/card/CardCangkul.hpp"

template<class T>
Card<T>::Card(T type, int number): type(type), number(number) {}

template<class T>
T Card<T>::getType() const {
    return type;
}

template<class T>
int Card<T>::getNumber() const {
    return number;
}

template
class Card<CardCandyType>;

template
class Card<CardCangkulType>;