#ifndef CANGKULGAMEENGINE_HPP
#define CANGKULGAMEENGINE_HPP

#include "../deck/GameDeckCangkul.hpp"
#include "../deck/TableDeckCangkul.hpp"
#include "../player/PlayerCangkul.hpp"
#include "CangkulDeckManager.hpp"

class CangkulGameEngine
{
public:
    CangkulGameEngine();

    ~CangkulGameEngine();

    void main();

protected:
    void beginGame();
    void runRound();

    CangkulDeckManager deckManager;
    PlayerCangkul **players;
    vector<PlayerCangkul *> leaderboards;
    vector<PlayerCangkul *> lostLeaderboards;
    vector<PlayerCangkul *> turns;
};

#endif