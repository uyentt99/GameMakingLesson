#pragma once
#include "State.h"
#include "iostream"
using namespace std;

class Opened : public State {
public:
    Opened();
    ~Opened();
    void close(Door* d);
    void lock(Door* d);
};