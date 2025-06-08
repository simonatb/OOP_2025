#pragma once
#include "Employee.h"

class Manager : virtual public Employee {
private:
	char* project;

	void copyFrom(const Manager& other);
	void free();
public:
	Manager(const char* name, int id, const char* project);
	Manager(const Manager& other);
	Manager& operator=(const Manager& other);
	~Manager();

	const char* getProject() const;

	void printInfo() const override;
};

