#include "FullHouse.hpp"
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using std::greater;
using std::sort;
using std::vector;
using std::map;
using std::pair;

FullHouse::FullHouse(const vector<CardCandy> &cards) : Comboable(7) {
    /** Format combo value
     *
     * Highest three pair | colors | highest two pair | colors
     *
     * Example:
     * highest three pair 13 with colors 3 2 1
     * highest two pair  5 with color 2 1
     * will have combo value of
     * 133210521
     *
     * Formula:
     * highest three pair number * 10^7 +
     * highest three pair card type * 10^6 +
     * second highest three pair card type * 10^5 +
     * third highest three pair card type * 10^4 +
     * highest two pair number * 10^2 +
     * highest two pair card type * 10 +
     * second highest two pair card type
     */
    map<int, vector<int>> counter;

    for (auto &card: cards) {
        if (counter.find(card.getNumber()) == counter.end()) {
            counter.insert(pair<int, vector<int>>(card.getNumber(), vector<int>()));
        }

        counter[card.getNumber()].push_back(card.getType());
    }

    // find the highest three pair
    int maxThree = -1;
    for (auto &each: counter) {
        if (each.second.size() >= 3) {
            if (each.first > maxThree) {
                maxThree = each.first;
            }
        }
    }

    if (maxThree == -1) {
        return; // no fullhouse
    }

    vector<int> threeTypes = counter[maxThree];
    sort(threeTypes.begin(), threeTypes.end(), greater<>());
    counter.erase(maxThree);

    // find the highest two pair
    int maxTwo = -1;
    for (auto &each: counter) {
        if (each.second.size() >= 2) {
            if (each.first > maxTwo) {
                maxTwo = each.first;
            }
        }
    }

    if (maxTwo == -1) {
        return; // no fullhouse
    }

    vector<int> twoTypes = counter[maxTwo];
    sort(twoTypes.begin(), twoTypes.end(), greater<>());
    counter.erase(maxTwo);

    this->comboValue += maxThree * pow(10, 7); // highest three pair
    this->comboValue += threeTypes[0] * pow(10, 6); // highest three pair card type
    this->comboValue += threeTypes[1] * pow(10, 5); // second-highest three pair card type
    this->comboValue += threeTypes[2] * pow(10, 4); // third-highest three pair card type
    this->comboValue += maxTwo * pow(10, 2); // highest two pair number
    this->comboValue += twoTypes[0] * 10; // highest two pair card type
    this->comboValue += twoTypes[1]; // second-highest two pair card type
}
