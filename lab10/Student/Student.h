#pragma once
#include "Person.h"

namespace constants {
	constexpr size_t LENGTH = 10;
}

class Student : public Person {
private:
	char fn[constants::LENGTH];
public:
	Student(const char* name, int age, const char* fn);
	void setFn(const char* fn);
	const char* getFn() const;
};

