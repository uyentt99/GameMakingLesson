#pragma once
#pragma once
#include "State.h"
#include "iostream"
using namespace std;

class Closed : public State {
public:
    Closed();
    ~Closed();
    void opend(Door* d);
    void lock(Door* d);
};