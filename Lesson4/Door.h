#pragma once
#include "iostream"
using namespace std;
class Door {
    class State* current;
public:
    Door();
    void setCurrent(State* s);
    void opend();
    void close();
    void lock();
    void unlock();
};




