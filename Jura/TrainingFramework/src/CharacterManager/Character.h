#pragma once
#include "iostream"
#include "GameStates/GameStatebase.h"

class Character : public Animation2D{
    class State* current;
public:
    Character();
    void setCurrent(State* s);
    void run();
    void jump();
    void dead();
    void idle();
    void slide();
    void setTexture(std::string picName, int numFrame);
    void Update(float deltaTime) override;;
    void UpdateStop(float deltaTime);
    void UpdateBackRun(float deltaTime);
    void UpdateLoop(float deltaTime);
};




