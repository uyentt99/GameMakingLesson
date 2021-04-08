#pragma once
#include "State.h"
#include "iostream"
#include "Dead.h"

using namespace std;

class Idle : public State {
public:
    Idle();
    ~Idle();
};