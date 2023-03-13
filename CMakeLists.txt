cmake_minimum_required(VERSION 3.16)
project(MZC_Opsional)

set(CMAKE_CXX_STANDARD 17)

add_executable(MZC_Opsional
        src/main.cpp
        src/base/card/Valuable.cpp
        src/base/card/Card.cpp
        src/base/deck/InventoryHolder.cpp
        src/base/deck/GameDeck.cpp
        src/base/deck/PlayerDeck.cpp
        src/base/deck/TableDeck.cpp
        src/base/player/Player.cpp
        src/utils/reader.cpp
        src/candy/card/CardCandy.cpp
        src/candy/player/PlayerCandy.cpp
        src/candy/deck/GameDeckCandy.cpp
        src/candy/deck/PlayerDeckCandy.cpp
        src/candy/game-engine/PointManager.cpp
        src/candy/game-engine/RoundManager.cpp
        src/candy/abilities/AbilityCard.cpp
        src/candy/abilities/SwapCard.cpp
        src/candy/abilities/Abilityless.cpp
        src/candy/abilities/Quadruple.cpp
        src/candy/combo/Comboable.cpp
        src/candy/combo/TwoPair.cpp
        src/candy/game-engine/AbilitiesManager.cpp
        src/candy/combo/FullHouse.cpp
        src/candy/combo/FourOfAKind.cpp
        src/candy/candy.cpp
        src/candy/abilities/AbilityStatus.cpp
        src/cangkul/card/CardCangkul.cpp
        src/cangkul/deck/GameDeckCangkul.cpp
        src/cangkul/deck/PlayerDeckCangkul.cpp
        src/cangkul/deck/TableDeckCangkul.cpp
        src/cangkul/player/PlayerCangkul.cpp
        src/main.cpp src/candy/game-engine/DeckManager.cpp
        src/candy/abilities/Reroll.cpp
        src/candy/abilities/Switch.cpp
        src/candy/abilities/Quarter.cpp
        src/candy/abilities/Reverse.cpp
        src/candy/game-engine/GameEngine.cpp
        src/candy/combo/Flush.cpp
        src/candy/combo/HighCard.cpp
        src/candy/combo/Pair.cpp
        src/candy/combo/Straight.cpp
        src/candy/combo/StraightFlush.cpp
        src/candy/combo/ThreeOfAKind.cpp
        src/candy/deck/TableDeckCandy.cpp 
        src/utils/max.cpp 
        src/cangkul/game-engine/CangkulGameEngine.cpp 
        src/cangkul/cangkul.cpp 
        src/utils/string.cpp
        src/utils/interface.cpp)
