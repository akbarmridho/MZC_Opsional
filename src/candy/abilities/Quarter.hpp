#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "AbilityCard.hpp"

class Quarter : public virtual AbilityCard
{
private:
public:
    /**
     * @brief Construct a new Quarter object
     *
     */
    Quarter();

    /**
     * @brief Use the Quarter ability
     *
     */
    void use();
};

#endif