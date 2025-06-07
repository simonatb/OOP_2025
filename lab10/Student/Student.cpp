#include "Student.h"

Student::Student(const char* name, int age, const char* fn) :Person(name,age) {
	setFn(fn);
}

void Student::setFn(const char* fn) {
	if (strlen(fn) > constants::LENGTH) {
		strcpy(this->fn, fn);
	}
}
const char* Student::getFn() const {
	return fn;
}
