#include "Locked.h"
#include "Door.h"
#include "Closed.h"

Locked::Locked(){
    cout << "   Locked-ctor ";
 };

Locked::~Locked()
{
    cout << "   dtor-Locked\n";
};

void Locked:: opend(Door* d){
        cout << "   please unlock first\n";
 }

void Locked::unlock(Door* d){
    cout << "   going from Locked to Closed";
    d->setCurrent(new Closed());
    delete(this);
}

