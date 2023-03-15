#include "GameEngine.hpp"
#include <iostream>
#include <iterator>
#include "../../utils/max.hpp"
#include "../../utils/interface.hpp"
#include "../../utils/string.hpp"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream_iterator;

GameEngine::GameEngine()
{
}

void GameEngine::start()
{
    clearTerminal();
    cout << "\n\nSelamat datang di" << cyellow() << " Candy Land\n"
         << reset() << endl;
    cin.ignore();
    for (int i = 0; i < 7; i++)
    {
        cout << "\nMasukkan nama player ke-" << i + 1 << ":\n> ";
        string name;
        getline(cin, name);
        trim(name);
        clearTerminal();
        if (name.size() == 0)
        {
            i--;
            cout << cred() << "Nama tidak valid, harap masukkan ulang.\n"
                 << reset();
        }
        else if (std::any_of(players, players + i, [name](PlayerCandy *p)
                             { return p->getName() == name; }))
        {
            i--;
            cout << cred() << "Nama " << cblue() << "'" << name << "'" << cred() << " telah digunakan, harap masukkan nama lain.\n"
                 << reset();
        }
        else
        {
            players[i] = new PlayerCandy(name);
        }
    }
    gameCounter = 1;
    DeckManager dm(players);
    deckManager = dm;
    PointManager pm(players);
    pointManager = pm;
    RoundManager rm(players);
    roundManager = rm;
    AbilitiesManager am(players, &deckManager, &pointManager, &roundManager);
    abilitiesManager = am;

    bool gameOver = false;
    do
    {
        cout << cyellow() << "\n=====MATCH " << gameCounter << "=====\n\n"
             << reset();
        gameOver = runMatch();
        gameCounter++;
    } while (!gameOver);
}

bool GameEngine::runMatch()
{
    roundCount = 1;
    deckManager.resetDeck();
    deckManager.initializePlayerDeck();
    do
    {
        cout << cyellow() << "\n=====ROUND " << roundCount << "====="
             << "\n\n"
             << reset();
        runRound();
        roundCount++;
    } while (roundManager.nextRound());

    string winnerName = max<PlayerCandy>(players, 7).getName();
    cout << cblue() << winnerName << reset() << " berhasil memenangkan match. " << cblue() << winnerName << cblue() << " mendapatkan " << cyellow() << pointManager.getCurrentRewardPoint() << reset() << " point.\n";
    bool gameOver = pointManager.givePointAndReset(winnerName);

    if (gameOver) {
        cout << "Permainan berakhir. \nPermainan dimenangkan oleh " << cblue() << winnerName << reset() << endl;  
    }

    pointManager.showLeaderboard();
    return gameOver;
}

void GameEngine::runRound()
{
    if (roundCount == 2)
    {
        abilitiesManager.shuffle();
    }
    bool willNext = true;
    do
    {
        PlayerCandy *p = roundManager.getCurrentPlayer();
        if (willNext)
        {
            cout << "Sekarang giliran " << *p << "\n";
            cout << "Tekan enter untuk memulai giliran" << endl;
            string temp;
            getline(cin, temp);
            clearTerminal();
            if (roundCount > 1)
                deckManager.showTableStatus();
            p->showStatus(roundCount == 1);
        }
        PlayerAction action = p->getAction(roundCount == 1);
        willNext = true;
        switch (action)
        {
        case ability:
            abilitiesManager.useAbility(p);
            break;
        case dbl:
            pointManager.multiplyReward(2);
            cout << "Point hadiah di-double menjadi " << cyellow() << pointManager.getCurrentRewardPoint() << reset() << endl;
            break;
        case half:
            if (pointManager.getCurrentRewardPoint() == 1)
            {
                cout << "Point hadiah sudah bernilai minimum. Half tidak mengubah point." << reset() << endl;
                break;
            }
            pointManager.divideReward(2);
            cout << "Point hadiah di-half menjadi " << cyellow() << pointManager.getCurrentRewardPoint() << reset() << endl;
            break;
        case status:
            willNext = false;
            showGameStatus();
            continue;
        default:
            clearTerminal();
            continue;
        }
        cout << "Tekan enter untuk mengakhiri giliran" << endl;
        string temp;
        getline(cin, temp);
        clearTerminal();
    } while (!willNext || roundManager.nextPlayer());
    if (roundCount < 6)
    {
        deckManager.openTableCard();
    }
}

void GameEngine::showGameStatus()
{
    cout << "\n=====GAME STATUS=====\n\n";
    cout << "Match\t: " << gameCounter << endl;
    cout << "Round\t: " << roundCount << endl;
    cout << "Points\t: " << pointManager.getCurrentRewardPoint() << endl;
    pointManager.showLeaderboard();
}