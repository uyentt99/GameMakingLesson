#include "Running.h"
#include "Character.h"
#include "Sliding.h"

Running:: Running(){
    printf("new Run state \n");
};

Running::~Running(){
};

void Running::update(Character* d, float deltaTime) {
    d->UpdateLoop(deltaTime);
}
