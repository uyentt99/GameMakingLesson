#pragma once
#include "iostream"
using namespace std;
class Door;
class State {
public:
    virtual void opend(Door* d);
    virtual void close(Door* d);
    virtual void lock(Door * d);
    virtual void unlock(Door* d);
};