#include "Valuable.hpp"

bool Valuable::operator<(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();
    if (thisPair.first == otherPair.first) {
        return thisPair.second < otherPair.second;
    }

    return thisPair.first < otherPair.first;
}

bool Valuable::operator>(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();
    if (thisPair.first == otherPair.first) {
        return thisPair.second > otherPair.second;
    }

    return thisPair.first > otherPair.first;
}

bool Valuable::operator==(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();
    return thisPair.first == otherPair.first && thisPair.second == otherPair.second;
}
