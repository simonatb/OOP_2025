#include "Person.h"

void Person::copyFrom(const Person& other) {
	length = other.length;
	age = other.age;
	name = new char[length];
	std::strcpy(name, other.name);
}

void Person::moveFrom(Person&& other) noexcept {
	name = other.name;
	other.name = nullptr;
	length = other.length;
	age = other.age;
	other.length = other.age = 0;
}

void Person::free() {
	delete[] name;
	name = nullptr;
	length = age = 0;
}

Person::Person(const char* name, int age) {
	this->age = age;
	size_t len = strlen(name);
	this->name = new char[len];
	strcpy(this->name, name);
}

Person::Person(const Person& other) {
	copyFrom(other);
}

Person::Person(Person&& other) noexcept {
	moveFrom(std::move(other));
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Person& Person::operator=(Person&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Person::~Person() {
	free();
}