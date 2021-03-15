#include <iostream>
#include "StaticObject.cpp"
using namespace std;
class Tree : public StaticObject {
public:
	Tree(int id, const char name[], const char position[]) : StaticObject(id, name, position) {}
	~Tree() {
		cout << "Delete Tree; ";
	}
	void move() {
		cout <<"Tree "<< getName() << " can't move\n";
	}
};