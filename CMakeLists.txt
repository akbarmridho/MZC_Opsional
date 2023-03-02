cmake_minimum_required(VERSION 3.25)
project(MZC_Opsional)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/base)
include_directories(src/base/card)
include_directories(src/base/deck)
include_directories(src/base/player)
include_directories(src/candy)
include_directories(src/candy/abilities)
include_directories(src/candy/card)
include_directories(src/candy/combo)
include_directories(src/candy/deck)
include_directories(src/candy/game-engine)
include_directories(src/candy/player)
include_directories(src/cangkul)

file(GLOB src
        "src/base/*.hpp"
        "src/base/*.cpp"
        "src/base/card/*.hpp"
        "src/base/card/*.cpp"
        "src/base/deck/*.hpp"
        "src/base/deck/*.cpp"
        "src/base/player/*.hpp"
        "src/base/player/*.cpp"
        "src/candy/*.hpp"
        "src/candy/*.cpp"
        "src/candy/abilities/*.hpp"
        "src/candy/abilities/*.cpp"
        "src/candy/card/*.hpp"
        "src/candy/card/*.cpp"
        "src/candy/combo/*.hpp"
        "src/candy/combo/*.cpp"
        "src/candy/deck/*.hpp"
        "src/candy/deck/*.cpp"
        "src/candy/game-engine/*.hpp"
        "src/candy/game-engine/*.cpp"
        "src/candy/player/*.hpp"
        "src/candy/player/*.cpp"
        )

add_executable(MZC_Opsional
        ${src}
        src/main.cpp)
