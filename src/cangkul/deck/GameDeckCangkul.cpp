#include <sstream>
#include <vector>
#include <random>

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::stringstream;

#include "GameDeckCangkul.hpp"
#include "../../utils/reader.hpp"
#include "../../base/exception/DeckException.hpp"

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

        if (checker[type][number]) {
            throw DuplicateDeckException(line);
        } else {
            checker[type][number] = true;
        }

        CardCangkul card((CardCangkulType) type, number);
        this->cards.push_back(card);
    }

    if (this->getCount() != 52) {
        throw IncompleteDeckException();
    }
}

void GameDeckCangkul::shuffle() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distributor(0, 52);

    this->reset();
    vector<CardCangkul> holder;

    for (auto &type: {spade, heart, diamond, club}) {
        for (int i = 1; i <= 13; i++) {
            CardCangkul card(type, i); // ignore this error for now
            holder.push_back(card);
        }
    }

    while (!holder.empty()) {
        int idx = distributor(generator) % holder.size();
        this->cards.push_back(holder[idx]);
        holder.erase(holder.begin() + idx);
    }
}
