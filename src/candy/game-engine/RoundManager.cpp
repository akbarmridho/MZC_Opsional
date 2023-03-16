#include "./RoundManager.hpp"

RoundManager::RoundManager() {}

RoundManager::RoundManager(PlayerCandy *players[7])
{
    currentPlayerIdx = 0;
    roundCountRM = 1;
    for (int i = 0; i < 7; i++)
    {
        this->players[i] = players[i];
    }
}

PlayerCandy *RoundManager::getCurrentPlayer()
{
    return players[this->currentPlayerIdx];
}

bool RoundManager::nextPlayer()
{
    if (this->currentPlayerIdx == 6)
    {
        // this->nextRound();
        return false;
    }
    this->currentPlayerIdx++;
    return true;
}

bool RoundManager::nextRound()
{
    PlayerCandy *temp = this->players[0];
    for (int i = 0; i < 6; i++)
    {
        this->players[i] = this->players[i + 1];
    }
    this->players[6] = temp;

    this->currentPlayerIdx = 0;

    if (roundCountRM == 7)
    {
        roundCountRM = 1;
        return false;
    }
    else
    {
        roundCountRM++;
        return true;
    }
}

void RoundManager::reversePlayer()
{
    if (this->currentPlayerIdx != 6)
    {
        std::cout << "sisa urutan eksekusi giliran ini : \n"
                  << std::endl;
        for (int i = this->currentPlayerIdx + 1; i < 7; i++)
        {
            std::cout << this->players[i]->getName() << std::endl;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "tidak ada sisa urutan eksekusi giliran" << std::endl;
    }

    if (currentPlayerIdx > 0)
    {
        PlayerCandy **tempBefore = new PlayerCandy *[this->currentPlayerIdx];
        for (int i = 0; i < this->currentPlayerIdx; i++)
        {
            tempBefore[i] = this->players[i];
        }
        for (int i = 0; i < currentPlayerIdx; i++)
        {
            this->players[i] = tempBefore[currentPlayerIdx - i - 1];
        }
        delete[] tempBefore;
    }
    if (currentPlayerIdx < 6)
    {
        PlayerCandy **tempAfter = new PlayerCandy *[7 - this->currentPlayerIdx];
        for (int i = this->currentPlayerIdx; i < 7; i++)
        {
            tempAfter[i - this->currentPlayerIdx] = this->players[i];
        }
        for (int i = this->currentPlayerIdx; i < 7; i++)
        {
            this->players[i] = tempAfter[7 - i - 1];
        }
        delete[] tempAfter;
    }

    // bakal dipanggil next player di game manager (currentPlayerIdx++) -> biar tetep player ke-7 (index 6)
    this->currentPlayerIdx--;
    std::cout << "urutan eksekusi giliran selanjutnya : \n";
    for (int i = 0; i < 7; i++)
    {
        std::cout << this->players[i]->getName() << std::endl;
    }
}