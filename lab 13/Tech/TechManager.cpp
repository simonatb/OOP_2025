#include "TechManager.h"

TechManager::TechManager(const char* name, int id, const char* project, const char* specialization) : Manager(name,id,project), Engineer(name,id,specialization) ,Employee(id,name){}

TechManager::TechManager(const TechManager& other) : Manager(other) ,Engineer(other), Employee(other) {}

TechManager& TechManager::operator=(const TechManager& other) {
	if (this != &other) {
		Manager::operator=(other);
		Engineer::operator=(other);
	}
	return *this;
}
TechManager::~TechManager() {}

void TechManager::printInfo() const {
	std::cout << "name: " << this->getName() << " id: " << this->getId() << " specialization: " << this->getSpecialization() <<" project: "<< this->getProject() << "\n";
}

void TechManager::assignTask(const char* task) const {
	std::cout << "task manager " << this->getName() << " assigns task " << task << "\n";
}