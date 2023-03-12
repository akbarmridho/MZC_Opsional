cmake_minimum_required(VERSION 3.16)
project(MZC_Opsional)

set(CMAKE_CXX_STANDARD 17)

add_executable(MZC_Opsional
        src/main.cpp
        src/base/card/Card.cpp
        src/base/deck/InventoryHolder.cpp
        src/base/deck/GameDeck.cpp
        src/base/deck/PlayerDeck.cpp
        src/base/deck/TableDeck.cpp
        src/base/player/Player.cpp
        src/candy/deck/GameDeckCandy.cpp
        src/utils/reader.cpp
        src/utils/max.cpp
        src/candy/abilities/AbilityCard.cpp
        src/candy/abilities/SwapCard.cpp
        src/candy/abilities/Abilityless.cpp
        src/candy/abilities/Quadruple.cpp
        src/candy/combo/Comboable.cpp
        src/candy/combo/TwoPair.cpp
        src/candy/deck/GameDeckCandy.cpp
        src/candy/deck/PlayerDeckCandy.cpp
        src/candy/game-engine/AbilitiesManager.cpp
        src/candy/game-engine/PointManager.cpp
        src/candy/game-engine/GameEngine.cpp
        src/base/card/Valuable.cpp
        src/candy/combo/FullHouse.cpp
        src/candy/combo/FourOfAKind.cpp
        src/candy/candy.cpp
        src/main.cpp)
