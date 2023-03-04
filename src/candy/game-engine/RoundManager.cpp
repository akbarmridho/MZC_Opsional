#include "RoundManager.hpp"

RoundManager::RoundManager(PlayerCandy players[])
{
    for (int i = 0; i < 7; i++)
    {
        this->players.push_back(players[i]);
    }
    this->currentPlayerIdx = 0;
    this->roundCountRM = 1;
}

PlayerCandy RoundManager::getCurrentPlayer()
{
    return this->players[this->currentPlayerIdx];
}

bool RoundManager::nextPlayer()
{
    if (currentPlayerIdx == 6)
    {
        // this->nextRound();
        return false;
    }
    this->currentPlayerIdx++;
    return true;
}

bool RoundManager::nextRound()
{
    this->players.push_back(this->players.front());
    this->players.pop_front();
    this->currentPlayerIdx = 0;

    if (this->roundCountRM == 7) {
        this->roundCountRM = 1;
        return false;
    } else {
        this->roundCountRM++;
        return true;
    }
}

void RoundManager::reversePlayer()
{
    if (this->currentPlayerIdx != 6) {
        std::cout << "sisa urutan eksekusi giliran ini : ";
        for (int i = this->currentPlayerIdx + 1; i < 7; i++)
        {
            std::cout << this->players[i].getName() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "tidak ada sisa urutan eksekusi giliran" << std::endl;
    }

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

    std::cout << "urutan eksekusi giliran selanjutnya : ";
    for (int i = 0; i < 7; i++)
    {
        std::cout << this->players[i].getName() << " ";
    }
    std::cout << std::endl;
}