#pragma once
#include <iostream>

class MyString {
private:
	char* string;
	size_t size;
	size_t capacity;

	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other) noexcept;
	void resize();
	void free();
public:
	MyString();
	MyString(const char* text);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	size_t getSize() const;
	size_t getCapacity() const;

	const char* c_str() const;
	MyString& operator+=(const MyString& other);
	MyString& operator+=(char ch);

	const char& operator[](size_t index) const;
	char& operator[](size_t index);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::istream& operator>>(std::istream& is, MyString& str);
};
std::ostream& operator<<(std::ostream& os, const MyString& str);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
