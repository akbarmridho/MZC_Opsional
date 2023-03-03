#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "AbilitiesManager.hpp"
#include "DeckManager.hpp"
#include "PointManager.hpp"
#include "RoundManager.hpp"

class GameEngine
{
protected:
    AbilitiesManager abilitiesManager;
    DeckManager deckManager;
    PointManager pointManager;
    RoundManager roundManager;
    PlayerCandy* players[7];
    int roundCount; // ronde 1 sampai 6 (atau 7?)
    int gameCounter; // game ke 1 sampe inf

public:
    GameEngine(); // initialize game
    void start();
    [[nodiscard]] PlayerCandy*[] getPlayers() const;
};

#endif