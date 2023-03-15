#ifndef COMBOABLE_HPP
#define COMBOABLE_HPP

#include <utility>
#include "../../base/card/Valuable.hpp"

class Comboable : public Valuable {
protected:
    int level;
    unsigned long long comboValue;

public:
    explicit Comboable(int level);

    Comboable(int level, unsigned long long int comboValue);

    [[nodiscard]] value_pair_t value() const override;
};

#endif