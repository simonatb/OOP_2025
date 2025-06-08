#pragma once
#include "Employee.h"

class Engineer : virtual public Employee {
private:
	char* specialization;

	void copyFrom(const Engineer& other);
	void free();
public:
	Engineer(const char* name, int id, const char* specialization);
	Engineer(const Engineer& other);
	Engineer& operator=(const Engineer& other);
	~Engineer();

	const char* getSpecialization() const;

	void printInfo() const override;
};

