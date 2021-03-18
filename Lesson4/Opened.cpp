#include "Opened.h"
#include "Door.h"
#include "Closed.h"

Opened:: Opened(){
    cout << "   Opened-ctor ";
};

Opened::~Opened(){
    cout << "   dtor-Opend\n";
};

void Opened::close(Door* d){
    cout << "   going from Opened to Closed";
    d->setCurrent(new Closed());
    delete(this);
}

void Opened::lock(Door* d){
    cout << "   please close first\n";
}
