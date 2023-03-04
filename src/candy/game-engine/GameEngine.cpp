#include "GameEngine.hpp"
#include <iostream>
#include <iterator>

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
  AbilitiesManager am(this, players);
  abilitiesManager = am;
  DeckManager dm(players);
  deckManager = dm;
  PointManager pm(players);
  pointManager = pm;
  RoundManager rm(players);
  roundManager = rm;

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
    if (roundCount == 2)
    {
      abilitiesManager.shuffle();
    }
    roundFinished = runRound();
  } while (!roundFinished);
}

bool GameEngine::runRound()
{
  do
  {
    PlayerCandy &p = roundManager.getCurrentPlayer();
    p.getThenRunAction(roundCount == 1);
  } while (!roundManager.nextPlayer());
}