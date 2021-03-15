#pragma once
#include <iostream>
#include "DynamicObject.cpp"
using namespace std;
class Motorbike : public DynamicObject {
public:
	 Motorbike(int id, const char name[], const char position[]) : DynamicObject(id, name, position) {}
	 ~Motorbike() {
		 cout << "Delete Motorbike; ";
	 }
	void move() {
		cout << "Move motorbike " << getName()<<"\n";
	}
};