#include "Engineer.h"

void Engineer::copyFrom(const Engineer& other) {
	specialization = new char[strlen(other.specialization) + 1];
	strcpy(specialization, other.specialization);
}

void Engineer::free() {
	delete[] specialization;
	specialization = nullptr;
}

Engineer::Engineer(const char* name, int id, const char* specialization) : Employee(id, name) {
	this->specialization = new char[strlen(specialization) + 1];
	strcpy(this->specialization, specialization);
}

Engineer::Engineer(const Engineer& other) : Employee(other) {
	copyFrom(other);
}

Engineer& Engineer::operator=(const Engineer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
		Employee::operator=(other);
	}
	return *this;
}

Engineer::~Engineer() {
	free();
}

const char* Engineer::getSpecialization() const {
	return specialization;
}

void Engineer::printInfo() const {
	std::cout << "name: " << this->getName() << " id: " << this->getId() << " specialization: " << specialization << "\n";

}