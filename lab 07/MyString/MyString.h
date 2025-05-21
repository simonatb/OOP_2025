#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

constexpr size_t CAPACITY = 24;
constexpr size_t BUFFER_SIZE = 1024;

class MyString {
private:
	char* data;
	size_t length;
	size_t capacity;

	void resize(size_t min);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();

public:
	MyString();
	MyString(const char* word);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	size_t getSize() const;
	size_t getCapacity() const;

	const char* c_str() const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	MyString& operator +=(const MyString& other);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);

	MyString substr(size_t begin, size_t count);

};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
