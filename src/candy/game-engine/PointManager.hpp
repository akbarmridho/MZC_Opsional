#ifndef POINTMANAGER_HPP
#define POINTMANAGER_HPP

#include "../player/PlayerCandy.hpp"
#include <map>
#include <utility>

using std::map;
using std::pair;

class PointManager
{
public:
    PointManager();
    /**
     * Berikan poin ke player, dan reset current reward jadi 64 point
     * Identifier berdasarkan nama player
     */
    void givePointAndReset(string &);

    /**
     * Kalikan current reward dengan angka tertentu.
     */
    void multiplyReward(int);

    /**
     *  Bagi current reward dengan a
     * Hasil minimal point menjadi 1.
     */
    void divideReward(int);

    pair<string, long> getHighestScore();

    [[nodiscard]] int getCurrentRewardPoint() const;

protected:
    int currentRewardPoint;
    map<string, long> player;
};

#endif