#pragma once
#include <iostream>

#pragma warning(disable : 4996)


class Employee {
private:
	char* name;
	int id;

	void copyFrom(const Employee& other);
	void free();
public:
	Employee(int id, const char* name);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	virtual ~Employee();

	const char* getName() const;
	int getId() const;

	virtual void printInfo() const;
};

