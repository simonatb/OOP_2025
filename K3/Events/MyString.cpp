#include "MyString.h"

void MyString::copyFrom(const MyString& other) {
	string = new char[other.capacity];
	capacity = other.capacity;
	size = other.size;
	for (size_t i = 0;i < size;i++) {
		string[i] = other.string[i];
	}
}

void MyString::moveFrom(MyString&& other) noexcept {
	string = other.string;
	capacity = other.capacity;
	size = other.size;
	other.size = other.capacity = 0;
	other.string = nullptr;
}

void MyString::resize() {
	capacity *= 2;
	char* newData = new char[capacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = string[i];
	}
	delete[] string;
	string = newData;
}

void MyString::free() {
	delete[] string;
	string = nullptr;
	size = capacity = 0;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* text) {
	size = strlen(text);
	capacity = size * 2;
	string = new char[capacity+1];
	strcpy(string, text);
}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept {
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString() {
	free();
}

size_t MyString::getSize() const {
	return size;
}

size_t MyString::getCapacity() const {
	return capacity;
}

const char* MyString::c_str() const {
	return string;
}

MyString& MyString::operator+=(const MyString& other) {
	size += strlen(other.string);
	if (size >= capacity) {
		resize();
	}
	std::strncat(string, other.string, other.size);
	return *this;
}

MyString& MyString::operator+=(char ch) {
	if (size == capacity) {
		resize();
	}
	string[size++] = ch;
	return *this;
}

const char& MyString::operator[](size_t index) const {
	return string[index];
}

char& MyString::operator[](size_t index) {
	return string[index];
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString res(lhs);
	res += rhs;
	return res;
}

std::istream& operator>>(std::istream& is, MyString& str) {
	char buff[1024];
	is >> buff;

	size_t buffSize = strlen(buff);
	if (buffSize >= str.getCapacity()) {
		str.resize();
	}
	strcpy(str.string, buff);
	str.size = buffSize;
	return is;
}

bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
	return !(lhs == rhs);
}