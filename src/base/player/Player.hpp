#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using std::string;

class Player
{
protected:
    string name;

public:
    Player();
    explicit Player(string);
    virtual bool operator>(const Player &) = 0;
    virtual bool operator>=(const Player &) = 0;
    virtual bool operator<(const Player &) = 0;
    virtual bool operator<=(const Player &) = 0;
    virtual bool operator==(const Player &) = 0;
};

#endif