#ifndef PLAYERDECKCANDY_HPP
#define PLAYERDECKCANDY_HPP

#include "../../base/deck/PlayerDeck.hpp"
#include "../card/CardCandy.hpp"
#include "./TableDeckCandy.hpp"
#include <functional>
using std::function;

class PlayerDeckCandy : virtual public PlayerDeck<CardCandy>
{
private:
    bool comboComputed;
    vector<Comboable *> combos;

public:
    PlayerDeckCandy();
    ~PlayerDeckCandy();

    vector<CardCandy> const &getCards() const;

    void resetDeck();
    void computeCombos(TableDeckCandy &);

    bool operator<(PlayerDeckCandy &other);
    bool operator>(PlayerDeckCandy &other);
};
#endif