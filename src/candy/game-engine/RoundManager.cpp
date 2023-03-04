#include "RoundManager.hpp"

RoundManager::RoundManager(PlayerCandy players[], int* roundCount)
{
    for (int i = 0; i < 7; i++)
    {
        this->players.push_back(players[i]);
    }
    this->currentPlayer = this->players.begin();
    this->roundCount = *roundCount;
}

PlayerCandy RoundManager::getCurrentPlayer()
{
    return *this->currentPlayer;
}

bool RoundManager::nextPlayer()
{
    if (currentPlayer == players.end())
    {
        this->nextRound();
        return false;
    }
    this->currentPlayer++;
    return true;
}

void RoundManager::nextRound()
{
    this->roundCount++;
    this->players.push_back(this->players.front());
    this->players.pop_front();
    this->currentPlayer = this->players.begin();
}