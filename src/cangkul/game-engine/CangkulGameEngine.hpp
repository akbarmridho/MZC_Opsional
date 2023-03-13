#ifndef CANGKULGAMEENGINE_HPP
#define CANGKULGAMEENGINE_HPP

#include "../deck/GameDeckCangkul.hpp"
#include "../deck/TableDeckCangkul.hpp"
#include "../player/PlayerCangkul.hpp"

class CangkulGameEngine {
public:
    CangkulGameEngine();

    ~CangkulGameEngine();

    void main();

    void beginGame();

protected:
    GameDeckCangkul gameDeck;
    TableDeckCangkul tableDeck;
    PlayerCangkul **players;
    vector<PlayerCangkul *> leaderboards;
    vector<PlayerCangkul *> turns;
};

#endif