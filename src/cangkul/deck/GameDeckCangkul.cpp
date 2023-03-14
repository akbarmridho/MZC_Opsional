#include <sstream>
#include <vector>
#include <random>

using std::mt19937;
using std::random_device;
using std::stringstream;
using std::uniform_int_distribution;
using std::vector;

#include "GameDeckCangkul.hpp"
#include "../../utils/reader.hpp"
#include "../../base/exception/DeckException.hpp"
#include <algorithm>
#include <random>

void GameDeckCangkul::fromFile(const string &path) {
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

        if (checker[type][number - 1]) {
            throw DuplicateDeckException(line);
        } else {
            checker[type][number - 1] = true;
        }

        CardCangkul card((CardCangkulType) type, number);
        this->cards.push_back(card);
    }

    if (this->getCount() != 52) {
        throw IncompleteDeckException();
    }
}

void GameDeckCangkul::shuffle() {
    for (auto &type: {spade, heart, diamond, club}) {
        for (int i = 1; i <= 13; i++) {
            CardCangkul card(type, i); // ignore this error for now
            this->cards.push_back(card);
        }
    }

    std::shuffle(this->cards.begin(), this->cards.end(), std::mt19937(std::random_device()()));
}

void GameDeckCangkul::shuffle(vector<CardCangkul> &waste) {
    this->cards = std::move(waste);
    std::shuffle(this->cards.begin(), this->cards.end(), std::mt19937(std::random_device()()));
}
