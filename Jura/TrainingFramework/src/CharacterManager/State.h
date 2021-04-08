#pragma once
#include "iostream"
#include "GameStates/GameStatebase.h"

using namespace std;
class Character;
class State {
public:
    virtual void run(Character* d);
    virtual void jump(Character* d);
    virtual void dead(Character * d);
    virtual void idle(Character* d);
    virtual void slide(Character* d);
    virtual void update(Character* d, float deltaTime);
};