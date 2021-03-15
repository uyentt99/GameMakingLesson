#pragma once
#include <iostream>
#include "BaseObject.cpp"
using namespace std;
class DynamicObject : public BaseObject {
public:
	DynamicObject(int id, const char name[], const char position[]) : BaseObject(id, name, position) {}
	~DynamicObject() {
		cout << "Dynamic Object; ";
	}
	void move() {
		cout << getName() << " could move\n";
	}
};