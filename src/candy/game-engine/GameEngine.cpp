#include "GameEngine.hpp"
#include <iostream>
#include <iterator>
#include "../../utils/max.hpp"

using std::cin;
using std::cout;
using std::istream_iterator;

GameEngine::GameEngine()
{
}

void GameEngine::start()
{
    istream_iterator<string> iit(cin);
    for (int i = 0; i < 7; i++)
    {
        cout << "Masukkan nama player ke-" << i + 1 << ":\n> ";
        players[i] = new PlayerCandy(*iit);
        iit++;
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

    deckManager.initializePlayerDeck();

    bool gameOver = false;
    do
    {
        gameOver = runMatch();
        gameCounter++;
    } while (!gameOver);
}

bool GameEngine::runMatch()
{
    deckManager.initializePlayerDeck();
    bool roundFinished = false;
    roundCount = 1;
    do
    {
        roundFinished = runRound();
        roundCount++;
    } while (!roundFinished);

    string winnerName = max<PlayerCandy>(players).getName();
    bool gameOver = pointManager.givePointAndReset(winnerName);
    pointManager.showLeaderboard();
    return gameOver;
}

bool GameEngine::runRound()
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
    } while (!roundManager.nextPlayer());
    return roundCount == 6;
}