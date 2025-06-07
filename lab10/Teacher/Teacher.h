#pragma once
#include "Person.h"
#include <iostream>

class Teacher : public Person {
private:
	char** subjects;
	size_t subjectsCount;

	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other) noexcept;
	void free();
public:
	Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount);
	Teacher(const Teacher& other);
	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other) noexcept;
	~Teacher();

};

