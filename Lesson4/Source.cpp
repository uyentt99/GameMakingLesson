#pragma once
#include "Door.cpp"
#include "iostream"
using namespace std;

int main()
{
    //void(Door:: * ptrs[])() ={
   //     Door::opend, Door::close, Door::lock, Door::unlock
   // };
    cout << "0: opend; 1: close; 2: lock; 3: unlock\n";
   // Door* myDoor = new Door();
    int num;
    while (1)
    {
        cout << "Enter 0/1/2/3: ";
        cin >> num;
       // (myDoor-> *ptrs[num])();
    }
}