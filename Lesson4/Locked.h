#pragma once
#include "State.h"
#include "iostream"
using namespace std;
class Locked : public State {
public:
    Locked();
    ~Locked();
    void opend(Door* d);
    void unlock(Door* d);
};