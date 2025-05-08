#include "Vector.h"

void Vector::copyFrom(const Vector& other) {
	length = other.length;
	data = new int[length] {};
	for (int i = 0;i < length; i++) {
		data[i] = other.data[i];
	}
}

void Vector::free() {
	delete[] data;
	data = nullptr;
	length = 0;
}

Vector::Vector() {
	length = DEFAULT_SIZE;
	data = new int[DEFAULT_SIZE] {};
}

Vector::Vector(size_t length, const int* nums) {
	this->length = length;
	for (int i = 0; i < length; i++) {
		data[i] = nums[i];
	}
}

Vector::Vector(const Vector& other) {
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::~Vector() {
	free();
}

void Vector::readFromFile(const char* filename) {
	std::ifstream ifs(filename, std::ios::binary);
	if (!ifs.is_open()) {
		return;
	}
	readFromFile(ifs);
	ifs.close();
}

void Vector::readFromFile(std::ifstream& ifs) {
	free();
	ifs.read((char*)&length, sizeof(size_t));
	data = new int[length] {};
	ifs.read((char*)&data, sizeof(int) * length);
}

void Vector::writeToFile(const char* filename) const{
	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs.is_open()) {
		return;
	}
	writeToFile(ofs);
	ofs.close();
}

void Vector::writeToFile(std::ofstream& ofs) const{
	ofs.write((const char*)&length, sizeof(size_t));
	ofs.write((const char*)&data, sizeof(int) * length);
}

Vector& Vector::operator+=(const Vector& other) {
	if (this->length != other.length) {
		return;
	}
	for (int i = 0;i < length; i++) {
		data[i] += other.data[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& other) {
	if (this->length != other.length) {
		return;
	}
	for (int i = 0;i < length; i++) {
		data[i] -= other.data[i];
	}
	return *this;
}

Vector& Vector::operator*=(int num) {
	for (int i = 0;i < length; i++) {
		data[i] *= num;
	}
	return *this;
}

int& Vector::operator[](size_t index) {
	if (index < 0) {
		return;
	}
	return data[index];
}

int Vector::operator[](size_t index) const {
	if (index < 0) {
		return;
	}
	return data[index];
}

std::ostream& operator<<(std::ostream& ofs, const Vector& vector) {
	ofs << "( ";
	for (int i = 0; i < vector.length - 1; i++) {
		ofs << vector.data[i] << " ,";
	}
	ofs << vector.data[vector.length - 1] << " )\n";
	return ofs;
}

std::istream& operator>>(std::istream& ifs, Vector& vector) {
	for (int i = 0; i < vector.length; i++) {
		ifs >> vector.data[i];
	}
	return ifs;
}

Vector operator+(const Vector& lhs, const Vector& rhs) {
	Vector result = lhs;
	result += rhs;
	return result;
}

Vector operator-(const Vector& lhs, const Vector& rhs) {
	Vector result = lhs;
	result -= rhs;
	return result;
}

Vector operator*(int num, const Vector& vec) {
	Vector result = vec;
	result *= num;
	return result;
}

Vector operator*(const Vector& vec, int num) {
	return num * vec;
}
