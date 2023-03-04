#include "Player.hpp"

#include <utility>

Player::Player() = default;

Player::Player(string name) : name(std::move(name)) {}

string Player::getName()
{
    return this->name;
}

std::ostream &operator<<(std::ostream &stream, Player &p)
{
    return stream << p.getName();
}