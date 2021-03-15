#pragma once
#include <iostream>
#include "BaseObject.cpp"
#include "Tree.cpp"
#include "House.cpp"
#include "Motorbike.cpp"
#include "Car.cpp"
using namespace std;

BaseObject* listObj[4];
void createList() {
    listObj[0] = new Tree(1, "cay tre", "ngoai Vuon");
    listObj[1] = new House(2, "nha ngoi", "phia truoc");
    listObj[2] = new Motorbike(3, "XX", "YY");
    listObj[3] = new Car(4, "AA", "BB");
}

void doObjAction() {
    cout << "Get name: ";
    for (auto obj : listObj) {
        cout << obj->getName() << "; ";
    }

    cout << "\n\nMove: \n";
    for (auto obj : listObj) {
        obj->move();
    }

    cout << "\nPrint position: \n";
    for (auto obj : listObj) {
        obj->printPosition();
    }

}

void removeObj() {
    cout << "\nRemove object:\n";
    for (auto obj : listObj) {
        delete(obj);
    }
}

int main() {
    createList();
    doObjAction();
    removeObj();
    cout << "\n";
    cout << "\nRun successful";
}

