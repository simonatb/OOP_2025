#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//Напишете клас Vector, който моделира математически n - мерен вектор с целочислени координати.За класа реализирайте :
//
//Конструктор по подразбиране, който създава тримерен нулев вектор
//Конструктор, който приема размер и масив от цели стойности
//Функции за четене и записване в двоичен файл
//Оператор << , който приема поток за за изход и извежда вектора във вида(a1, a2, …, an)

namespace {
	constexpr int DEFAULT_SIZE = 3;
}

class Vector {
private:
	int* data;
	size_t length;

	void copyFrom(const Vector& other);
	void free();

public:

	Vector();
	Vector(size_t length, const int* nums);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void readFromFile(const char* filename);
	void readFromFile(std::ifstream& ifs);

	void writeToFile(const char* filename) const;
	void writeToFile(std::ofstream& ofs) const;

	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(int num);

	int& operator[](size_t index);
	int operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& ofs, const Vector& vector);
	friend std::istream& operator>>(std::istream& ifs, Vector& vector);
};

Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(int num , const Vector& vec);
Vector operator*(const Vector& vec, int num);
