#ifndef VALUABLE_HPP
#define VALUABLE_HPP

#include <utility>

using std::pair;

// pair of level, value
typedef pair<int, double> value_pair_t;

class Valuable
{
public:
    [[nodiscard]] virtual value_pair_t value() const = 0;

    [[nodiscard]] bool operator<(const Valuable &other) const;

    [[nodiscard]] bool operator>(const Valuable &other) const;

    [[nodiscard]] bool operator==(const Valuable &other) const;
};

#endif