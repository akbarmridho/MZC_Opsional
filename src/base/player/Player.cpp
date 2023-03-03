#include "Player.hpp"

#include <utility>

Player::Player() = default;

Player::Player(string name) : name(std::move(name)) {}

string Player::getName() {
    return this->name;
}