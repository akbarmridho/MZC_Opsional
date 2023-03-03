cmake_minimum_required(VERSION 3.25)
project(MZC_Opsional)

set(CMAKE_CXX_STANDARD 17)

add_executable(MZC_Opsional
        src/main.cpp
        src/base/card/Card.cpp
        src/base/deck/InventoryHolder.cpp
        src/base/deck/GameDeck.cpp
        src/base/deck/PlayerDeck.cpp
        src/base/deck/TableDeck.cpp
        src/base/player/Player.cpp)
