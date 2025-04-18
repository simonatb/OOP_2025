#include "Polynom.h"
#include <fstream>
#include <iostream>
using namespace std;
constexpr int BUFFER_SIZE = 1024;

void Polynom::copyArray(const double* source, double* dest, size_t size) {
	for (int i = 0; i < size;i++) {
		dest[i] = source[i];
	}
}

void Polynom::free() {
	delete[] data;
	data = nullptr;
	n = 0;
}

void Polynom::copyFrom(const Polynom& other) {
	n = other.n;
	data = new double[n];
	copyArray(other.data, this->data, this->n);
}

void Polynom::resize(size_t newSize) {
	double* newData = new double[newSize];
	copyArray(this->data, newData, n);
	delete[] data;
	data = newData;
	n = newSize;
}

Polynom::Polynom(size_t n) : n(n) {
	data = new double[n];
}

Polynom::Polynom(const Polynom& other) {
	copyFrom(other);
}

Polynom& Polynom::operator=(const Polynom& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Polynom::~Polynom() {
	free();
}

void Polynom::load(const char* filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file\n";
		return;
	}
	double buffer[BUFFER_SIZE];
	int index = 0;
	while (true) {
		file >> buffer[index++];
		if (file.eof()) {
			break;
		}
	}
	file.close();

	if (index != n) {
		resize(index);
	}
	copyArray(buffer, this->data, index);
	n = index;
}

void Polynom::print() const {
	for (int i = n; i > 1; i--) {
		cout << data[n-i] << "x^" << n << " + ";
	}
	cout << data[n - 1] << "x + 1\n";
}

void Polynom::add(const Polynom& other) {
	if (other.n > n) {
		resize(other.n);
	}
	for (int i = 0; i < n; i++) {
		data[i] += other.data[i];
	}
}
