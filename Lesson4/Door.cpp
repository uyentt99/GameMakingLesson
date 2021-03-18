#include "Door.h"
#include "State.h"
#include "Opened.h"

Door::Door() {
    current = new Opened();
    cout << "\n";
}

void Door::setCurrent(State* s){
    current = s;
}

void Door::opend(){
    current->opend(this);
}

void Door::close(){
    current->close(this);
}

void Door::lock(){
    current->lock(this);
}

void Door::unlock(){
    current->unlock(this);
};




