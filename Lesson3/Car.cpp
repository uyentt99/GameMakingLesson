#pragma once
#include <iostream>
#include "DynamicObject.cpp"
using namespace std;
class Car : public DynamicObject {
public:
	Car(int id, const char name[], const char position[]) : DynamicObject(id, name, position) {}
	~Car() {
		cout << "Delete Car; ";
	}
	void move() {
		cout << "Move car " << getName()<<"\n";
	}
};