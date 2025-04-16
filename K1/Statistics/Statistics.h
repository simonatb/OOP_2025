#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Statistics
{
private:
	double* numbers;
	size_t numbersCount;

	void copyFrom(const Statistics& other);
	void free();
	void resize(size_t newSize);
	void copyArrays(const double* source, double* dest, size_t size);

public:
	Statistics(const double* numbers, size_t n);
	Statistics(const Statistics& other);
	Statistics& operator=(const Statistics& other);
	~Statistics();

	void load(const char* filename);
	double min() const;
	void printAvg() const;
	void combine(const Statistics& other);

	void print() const;
};
