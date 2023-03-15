#include "Valuable.hpp"

bool Valuable::operator<(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();

    if (thisPair.second == 0 && otherPair.second == 0) {
        return false;
    } else {
        if (thisPair.first == otherPair.first) {
            return thisPair.second < otherPair.second;
        }

        return thisPair.first < otherPair.first;
    }
}

bool Valuable::operator>(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();

    if (thisPair.second == 0 && otherPair.second == 0) {
        return false;
    } else {
        if (thisPair.first == otherPair.first) {
            return thisPair.second > otherPair.second;
        }

        return thisPair.first > otherPair.first;
    }
}

bool Valuable::operator==(const Valuable &other) const {
    auto thisPair = this->value();
    auto otherPair = other.value();

    if (thisPair.second == 0 && otherPair.second == 0) {
        return true;
    } else {
        return thisPair.first == otherPair.first && thisPair.second == otherPair.second;
    }
}
