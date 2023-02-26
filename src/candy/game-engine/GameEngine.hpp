#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

class GameEngine
{
protected:
    int current_reward_point = 64;

public:
    virtual int get_next_player() = 0;
    void multiply_reward(int);
};

#endif