#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Person {
private:
	char* name;
	size_t length;
	int age;

	void copyFrom(const Person& other);
	void moveFrom(Person&& other) noexcept;
	void free();
public:
	Person(const char* name, int age);
	Person(const Person& other);
	Person(Person&& other) noexcept;
	Person& operator=(const Person& other);
	Person& operator=(Person&& other) noexcept;
	~Person();
};

