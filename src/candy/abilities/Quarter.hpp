#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "AbilityCard.hpp"

class Quarter : public virtual AbilityCard {
private:
    PointManager *pointManager;
public:
    /**
     * @brief Construct a new Quarter object
     *
     */
    explicit Quarter(PointManager *pm);

    /**
     * @brief Use the Quarter ability
     *
     */
    void use() override;
};

#endif