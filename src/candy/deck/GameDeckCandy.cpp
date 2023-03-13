#include "GameDeckCandy.hpp"

#include "../../utils/reader.hpp"
#include "../../base/exception/DeckException.hpp"
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>

using std::vector;
using std::stringstream;

void GameDeckCandy::shuffle() {
    this->reset();

    for (auto &type: {green, blue, yellow, red}) {
        for (int i = 1; i <= 13; i++) {
            CardCandy card(type, i); // ignore this error for now
            this->cards.push_back(card);
        }
    }

    std::shuffle(this->cards.begin(), this->cards.end(), std::mt19937(std::random_device()()));
}

void GameDeckCandy::fromFile(const string &path) {
    this->reset();

    auto lines = readLines(path);
    bool checker[4][13] = {false};

    for (auto &line: lines) {
        stringstream stream(line);
        int type, number;

        stream >> type;
        stream >> number;

        if (type < 0 || type > 3) {
            throw InvalidDeckTypeException(line);
        }

        if (number < 1 || number > 13) {
            throw InvalidDeckNumberException(line);
        }

        if (checker[type][number]) {
            throw DuplicateDeckException(line);
        } else {
            checker[type][number] = true;
        }

        CardCandy card((CardCandyType) type, number);
        this->cards.push_back(card);
    }

    if (this->getCount() != 52) {
        throw IncompleteDeckException();
    }
}