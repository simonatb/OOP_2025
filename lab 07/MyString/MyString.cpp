#include "MyString.h"

void MyString::resize(size_t min) {
	char* copy = new char[min + 1];
	strcpy(copy, data);
	delete[] data;
	data = copy;
	capacity = min;
}

void MyString::copyFrom(const MyString& other) {
	capacity = other.capacity;
	length = other.length;
	data = new char[capacity];
	strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other) {
	capacity = other.capacity;
	other.capacity = 0;
	length = other.length;
	other.length = 0;
	data = other.data;
	other.data = nullptr;
}

void MyString::free() {
	delete[] data;
	data = nullptr;
	length = capacity = 0;
}

static size_t roundToPowerOfTwo(unsigned num) {
	unsigned result = 1;
	while (result < num) {
		result << 1;
	}
	return result;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* word) {
	if (!word) {
		word = "";
	}
	length = strlen(word);
	capacity = roundToPowerOfTwo(length);
	data = new char[capacity];
	strcpy(data, word);
}

MyString::MyString(const MyString& other) {
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept {
	moveFrom(std::move(other));
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
	return length;
}

size_t MyString::getCapacity() const {
	return capacity - 1;
}

const char* MyString::c_str() const {
	return data;
}

char& MyString::operator[](size_t index) {
	return data[index];
}
const char& MyString::operator[](size_t index) const {
	return data[index];
}

MyString& MyString::operator+=(const MyString& other) {
	if (length + other.length + 1 > capacity) {
		resize(length + other.length);
	}
	strncat(data, other.data, other.length);
	length += other.length;
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
	MyString res(lhs);
	res += rhs;
	return res;
}
std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << str;
}
std::istream& operator>>(std::istream& is, MyString& str) {
	char buff[BUFFER_SIZE];
	is >> buff;
	size_t buffSize = strlen(buff);
	if (buffSize >= str.capacity) {
		str.resize(buffSize);
	}
	strcpy(str.data, buff);
	str.length = buffSize;
}

MyString MyString::substr(size_t begin, size_t count) {
	if (begin + count > length) {
		return MyString("");
	}
	MyString res;
	res.capacity = roundToPowerOfTwo(count + 1);
	res.data = new char[res.capacity];
	strncat(res.data, data + begin, count);
	res.length = count;

	return res;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
	return !(lhs == rhs);
}
bool operator>(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs) {
	return lhs == rhs || lhs > rhs;
}
bool operator<(const MyString& lhs, const MyString& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs) {
	return lhs == rhs || lhs < rhs;
}
