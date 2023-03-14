#include "PointManager.hpp"
#include "../../utils/max.hpp"
#include <algorithm>
#include <iostream>

using std::copy;
using std::cout;
using std::endl;
using std::sort;

PointManager::PointManager()
{
}

PointManager::PointManager(PlayerCandy *players[7])
{
    currentRewardPoint = 64;
    for (int i = 0; i < 7; i++)
    {
        this->players.insert(pair<string, long>{players[i]->getName(), 0LL});
    }
}

bool PointManager::givePointAndReset(string &player)
{
    players[player] += currentRewardPoint;
    currentRewardPoint = 64;
    return players[player] > WIN_SCORE;
}

void PointManager::multiplyReward(int multiplier)
{
    currentRewardPoint *= multiplier;
}

void PointManager::divideReward(int divider)
{
    currentRewardPoint /= divider;
    if (currentRewardPoint < 1)
        currentRewardPoint = 1;
}

void PointManager::showLeaderboard() const
{
    vector<pair<string, long long>> sortedPoints;
    for (auto it = players.begin(); it != players.end(); it++)
    {
        auto el = *it;
        sortedPoints.push_back(el);
    }
    sort(sortedPoints.begin(), sortedPoints.end(),
         [](pair<string, long long> &a, pair<string, long long> &b)
         { return a.second > b.second; });
    cout << "Leaderboard:\n";
    for (int i = 0; i < sortedPoints.size(); i++)
    {
        cout << "\t" << i + 1 << ". " << sortedPoints[i].first << ": " << sortedPoints[i].second << endl;
    }
}

pair<string, long long> PointManager::getHighestScore() const
{
    return max(players);
}

long long PointManager::getCurrentRewardPoint() const
{
    return currentRewardPoint;
}