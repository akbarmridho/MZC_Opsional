#include "RoundManager.hpp"

RoundManager::RoundManager(PlayerCandy players[], int* roundCount)
{
    for (int i = 0; i < 7; i++)
    {
        this->players.push_back(players[i]);
    }
    this->currentPlayerIdx = 0;
    this->roundCount = *roundCount;
}

PlayerCandy RoundManager::getCurrentPlayer()
{
    return this->players[this->currentPlayerIdx];
}

bool RoundManager::nextPlayer()
{
    if (currentPlayerIdx == 6)
    {
        this->nextRound();
        return false;
    }
    this->currentPlayerIdx++;
    return true;
}

void RoundManager::nextRound()
{
    this->roundCount++;
    this->players.push_back(this->players.front());
    this->players.pop_front();
    this->currentPlayerIdx = 0;
}

void RoundManager::reversePlayer()
{
    std::deque<PlayerCandy> beforeCurrentPlayer;
    std::deque<PlayerCandy> afterCurrentPlayer;

    for (int i = 0; i < currentPlayerIdx; i++)
    {
        beforeCurrentPlayer.push_front(this->players.front());
        this->players.pop_front();
    }
    
    for (int i = this->currentPlayerIdx; i < 7; i++)
    {
        afterCurrentPlayer.push_front(this->players.front());
        this->players.pop_front();
    }

    this->players.clear();

    if (beforeCurrentPlayer.size() > 0)
    {
        this->players.insert(this->players.begin(), beforeCurrentPlayer.begin(), beforeCurrentPlayer.end());
    }

    if (afterCurrentPlayer.size() > 0)
    {
        this->players.insert(this->players.end(), afterCurrentPlayer.begin(), afterCurrentPlayer.end());
    }

    this->currentPlayerIdx = 6;
}