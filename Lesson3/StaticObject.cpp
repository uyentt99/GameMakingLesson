#pragma once
#include <iostream>
#include "BaseObject.cpp"
using namespace std;
class StaticObject : public BaseObject{
public:
	StaticObject(int id, const char name[], const char position[]) : BaseObject(id, name, position){}
	~StaticObject(){
		cout << "Static Object; ";
	}
	void move() {
		cout << getName() << " can't move\n";
	}
};