#ifndef COMBOABLE_HPP
#define COMBOABLE_HPP

#include <utility>
#include "../deck/PlayerDeckCandy.hpp"
#include "../deck/TableDeckCandy.hpp"

class Comboable : virtual public Valuable {
protected:
    int level;
    double comboValue;

public:
    explicit Comboable(int level);

    Comboable(int level, double comboValue);

    [[nodiscard]] value_pair_t value() const override;
};

#endif