#include "Teacher.h"

static char** copyArrayOfStrings(const char* const* strings, size_t size) {
	char** res = new char* [size];
	for (size_t i = 0; i < size; i++) {
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}
	return res;
}

static void freeArrayOfStrings(char** strings, size_t size) {
	for (size_t i = 0; i < size;i++) {
		delete[] strings[i];
	}
	delete[] strings;
}

void Teacher::copyFrom(const Teacher& other) {
	subjects = copyArrayOfStrings(other.subjects, other.subjectsCount);
	subjectsCount = other.subjectsCount;
}

void Teacher::moveFrom(Teacher&& other) noexcept {
	subjects = other.subjects;
	other.subjects = nullptr;
	subjectsCount = other.subjectsCount;
	other.subjectsCount = 0;
}

void Teacher::free() {
	freeArrayOfStrings(subjects, subjectsCount);
	subjectsCount = 0;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name,age) {
	this->subjects = copyArrayOfStrings(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

Teacher::Teacher(const Teacher& other) : Person(other){
	copyFrom(other);
}

Teacher::Teacher(Teacher&& other) noexcept : Person(std::move(other)) {
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(const Teacher& other) {
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Teacher& Teacher::operator=(Teacher&& other) noexcept {
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
	
}
Teacher::~Teacher() {
	free();
}