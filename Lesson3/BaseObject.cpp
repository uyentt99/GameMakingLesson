#pragma once
#include <string.h>
#include <iostream>
using namespace std;
class BaseObject {

public:
	int id;
	char* name;
	char* position;


	BaseObject(int id, const char name[], const char position[]) {
		this->id = id;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->position = new char[strlen(position) + 1];
		strcpy(this->position, position);
	}

	virtual~BaseObject() {
		cout << "object " << id << "\n";
		delete(name);
		delete(position);
	}

	int getId() {
		return id;
	}

	virtual char* getName() {
		return name;
	}

	void printPosition() {
		cout<<position<<"\n";
	}

	virtual void move() = 0;
};
