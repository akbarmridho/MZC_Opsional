#include "GameEngine.hpp"
#include <iostream>
#include <iterator>
#include "../../utils/max.hpp"
#include "../../utils/interface.hpp"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream_iterator;

bool isFirstForAll = false;

GameEngine::GameEngine()
{
}

void GameEngine::start()
{
    cout << "Selamat datang di Candy Land" << endl;
    cin.ignore();
    for (int i = 0; i < 7; i++)
    {
        cout << "\nMasukkan nama player ke-" << i + 1 << ":\n> ";
        string name;
        getline(cin, name);
        if (std::any_of(players, players + i, [name](PlayerCandy *p)
                        { return p->getName() == name; }))
        {
            i--;
            cout << "Nama '" << name << "' telah digunakan, harap masukkan nama lain.\n";
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
    isFirstForAll = true;
    do
    {
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
        cout << cyellow() << "\n\nROUND " << roundCount << "\n\n"
             << reset();
        runRound();
        roundCount++;
    } while (roundManager.nextRound());

    string winnerName = max<PlayerCandy>(players, 7).getName();
    bool gameOver = pointManager.givePointAndReset(winnerName);
    pointManager.showLeaderboard();
    return gameOver;
}

void GameEngine::runRound()
{
    if (roundCount == 2)
    {
        abilitiesManager.shuffle();
    }
    if (roundCount < 6)
    {
        deckManager.openTableCard();
    }
    do
    {
        PlayerCandy *p = roundManager.getCurrentPlayer();
        p->showStatus(roundCount == 1, isFirstForAll);
        isFirstForAll = false;
        PlayerAction action = p->getAction(roundCount == 1);
        switch (action)
        {
        case ability:
            abilitiesManager.useAbility(p);
            break;
        case dbl:
            pointManager.multiplyReward(2);
        case half:
            pointManager.divideReward(2);
        default:
            break;
        }
        clearTerminal();
    } while (roundManager.nextPlayer());
}