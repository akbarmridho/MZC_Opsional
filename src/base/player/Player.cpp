#include "Player.hpp"

#include <utility>

Player::Player() = default;

Player::Player(string name) : name(std::move(name)) {}