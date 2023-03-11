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
    do
    {

        roundFinished = runRound();
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
        PlayerCandy &p = roundManager.getCurrentPlayer();
        p.getThenRunAction(roundCount == 1);
    } while (!roundManager.nextPlayer());
    return roundCount == 6;
}