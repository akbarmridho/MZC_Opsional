#include "Card.hpp"

template <class T>
Card<T>::Card(T type, int number): type(type), number(number) {}

template <class T>
T Card<T>::getType() const {
    return type;
}

template <class T>
int Card<T>::getNumber() const {
    return number;
}