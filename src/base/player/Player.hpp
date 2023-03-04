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
    string getName();
    friend std::ostream &operator<<(std::ostream &stream, Player &p);
};

#endif