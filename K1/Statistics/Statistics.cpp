#include "Statistics.h"

constexpr int BUFFER_SIZE = 1024;

void Statistics::copyFrom(const Statistics& other) {
	numbersCount = other.numbersCount;
	numbers = new double[numbersCount];
	for (int i = 0; i < numbersCount; i++) {
		numbers[i] = other.numbers[i];
	}
}

void Statistics::free() {
	delete[] numbers;
	numbers = nullptr;
	numbersCount = 0;
}

Statistics::Statistics(const double* numbers, size_t n) {
	numbersCount = n;
	this->numbers = new double[numbersCount];
	copyArrays(numbers, this->numbers, numbersCount);
}

Statistics::Statistics(const Statistics& other) {
	copyFrom(other);
}

Statistics& Statistics::operator=(const Statistics& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Statistics::~Statistics() {
	free();
}

void Statistics::resize(size_t newSize) {
	double* newData = new double[newSize];
	copyArrays(numbers, newData, numbersCount);
	delete[] numbers;
	numbers = newData;
	numbersCount = newSize;
}

void Statistics::load(const char* filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Error while opening the file\n";
		return;
	}

	double buffer[BUFFER_SIZE];
	size_t index = 0;
	while (true) {
		file >> buffer[index++];
		if (file.eof()) {
			break;
		}
	}
	file.close();

	if (numbersCount < index) {
		resize(index);
	}
	copyArrays(buffer, numbers, index);
}

double Statistics::min() const {
	double min = numbers[0];
	for (int i = 1; i < numbersCount; i++) {
		if (min > numbers[i]) {
			min = numbers[i];
		}
	}
	return min;
}

void Statistics::printAvg() const {
	double sum = 0;
	for (int i = 0; i < numbersCount; i++) {
		sum += numbers[i];
	}
	sum /= numbersCount;
	cout << "average :" << sum << '\n';
}

void Statistics::combine(const Statistics& other) {
	if (other.numbersCount > numbersCount) {
		resize(other.numbersCount);
	}
	for (int i = 0; i < numbersCount; i++) {
		numbers[i] += other.numbers[i];
	}
}

void Statistics::copyArrays(const double* source, double* dest, size_t size) {
	for (int i = 0; i < size; i++) {
		dest[i] = source[i];
	}
}

void Statistics::print() const {
	for (int i = 0; i < numbersCount; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}
