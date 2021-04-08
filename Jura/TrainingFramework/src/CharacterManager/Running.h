#pragma once
#include "State.h"
#include "iostream"
#include "Dead.h"

using namespace std;

class Running : public State {
public:
    Running();
    ~Running();
    void update(Character* d, float deltaTime);
};