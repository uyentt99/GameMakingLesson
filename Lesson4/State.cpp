#include "State.h"
void State::opend(Door* d)
{
    cout << "   already Opened\n";
}
void State::close(Door* d)
{
    cout << "   already Closed\n";
}
void State::lock(Door* d)
{
    cout << "   already Locked\n";
}
void State::unlock(Door* d)
{
    cout << "   hasn't Looked\n";
}