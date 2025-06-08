#include "Manager.h"

void Manager::copyFrom(const Manager& other) {
	project = new char[strlen(other.project) + 1];
	strcpy(project, other.project);
}

void Manager::free() {
	delete[] project;
	project = nullptr;
}

Manager::Manager(const char* name, int id, const char* project) : Employee(id, name){
	this->project = new char[strlen(project) + 1];
	strcpy(this->project, project);
}

Manager::Manager(const Manager& other) : Employee(other) {
	copyFrom(other);
}

Manager& Manager::operator=(const Manager& other) {
	if (this != &other) {
		free();
		copyFrom(other);
		Employee::operator=(other);
	}
	return *this;
}

Manager::~Manager() {
	free();
}

const char* Manager::getProject() const {
	return project;
}

void Manager::printInfo() const {
	std::cout << "name: " << this->getName() << " id: " << this->getId() << " project: " << project << "\n";
}