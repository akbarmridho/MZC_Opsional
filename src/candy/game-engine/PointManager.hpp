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
    PointManager(PlayerCandy *[7]);
    /**
     * Berikan poin ke player, dan reset current reward jadi 64 point
     * Identifier berdasarkan nama player
     * @return bool player yang ditambahkan nilainya menjadi pemenang atau tidak
     */
    bool givePointAndReset(string &);

    /**
     * Kalikan current reward dengan angka tertentu.
     */
    void multiplyReward(int);

    /**
     *  Bagi current reward dengan a
     * Hasil minimal point menjadi 1.
     */
    void divideReward(int);

    void showLeaderboard() const;

    pair<string, long long> getHighestScore() const;

    [[nodiscard]] long long getCurrentRewardPoint() const;

protected:
    long long currentRewardPoint;
    map<string, long long> players;
    const static long long WIN_SCORE = 1LL << 32;
};

#endif