#include "Closed.h"
#include "Door.h"
#include "Opened.h"
#include "Locked.h"
Closed::Closed()
{
    cout << "   Closed-ctor ";
};

Closed::~Closed()
{
    cout << "   dtor-Closed\n";
};

void Closed::opend(Door* d)
{
    cout << "   going from Closed to Opened";
    d->setCurrent(new Opened());
    delete(this);
}

void Closed::lock(Door* d)
{
    cout << "   going from Closed to Locked";
    d->setCurrent(new Locked());
    delete(this);
};