#pragma once
#include <iostream>
#include "StaticObject.cpp"
using namespace std;
class House : public StaticObject {
public:
	House(int id, const char name[], const char position[]) : StaticObject(id, name, position) {}
	~House() {
		cout << "Delete House; ";
	}
	void move() {
		cout << "House " << getName() << " can't move\n";
	}
};