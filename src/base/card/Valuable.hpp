#ifndef VALUABLE_HPP
#define VALUABLE_HPP

#include <utility>

using std::pair;

typedef pair<int, double> value_pair_t;

class Valuable
{
public:
    virtual value_pair_t value() = 0;

    [[nodiscard]] bool operator<(const Valuable &other) const;
    [[nodiscard]] bool operator>(const Valuable &other) const;
    [[nodiscard]] bool operator==(const Valuable &other) const;
};

#endif