#ifndef VALUABLE_HPP
#define VALUABLE_HPP

#include <utility>

using std::pair;

typedef pair<int, double> value_pair;

class Valuable
{
public:
    virtual value_pair value() = 0;
};

#endif