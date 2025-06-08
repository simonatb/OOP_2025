#include "Employee.h"

void Employee::copyFrom(const Employee& other) {
	id = other.id;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Employee::free() {
	id = 0;
	delete[] name;
	name = nullptr;
}

Employee::Employee(int id, const char* name) : id(id) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Employee::Employee(const Employee& other) {
	copyFrom(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Employee::~Employee() {
	free();
}

const char* Employee::getName() const {
	return name;
}

int Employee::getId() const {
	return id;
}

void Employee::printInfo() const {
	std::cout <<"name: " << name << " id:" << id << "\n";
}