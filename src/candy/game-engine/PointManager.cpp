#include "PointManager.hpp"
#include "../../utils/max.hpp"
PointManager::PointManager(PlayerCandy **players)
{
  currentRewardPoint = 64;
  for (int i = 0; i < 7; i++)
  {
    this->players.insert(pair<string, long>{players[i]->getName(), 0L});
  }
}

void PointManager::givePointAndReset(string &player)
{
  players[player] += currentRewardPoint;
  currentRewardPoint = 64;
}

void PointManager::multiplyReward(int multiplier)
{
  currentRewardPoint *= multiplier;
}

void PointManager::divideReward(int divider)
{
  currentRewardPoint /= divider;
}

pair<string, long> PointManager::getHighestScore() const
{
  return max(players);
}

int PointManager::getCurrentRewardPoint() const
{
  return currentRewardPoint;
}