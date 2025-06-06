#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class ComplexNumbers {
private:
	double real;
	double im;
public:
	ComplexNumbers();
	ComplexNumbers(double real, double im);

	double getReal() const;
	double getIm() const;

	void setReal(double real);
	void setIm(double im);

	ComplexNumbers getConjugated() const;

	ComplexNumbers& operator+=(const ComplexNumbers& other);
	ComplexNumbers& operator-=(const ComplexNumbers& other);
	ComplexNumbers& operator*=(const ComplexNumbers& other);
	ComplexNumbers& operator/=(const ComplexNumbers& other);

	friend std::ostream& operator<<(std::ostream& os, const ComplexNumbers& other);
	friend std::istream& operator>>(std::istream& is, ComplexNumbers& other);

};

ComplexNumbers operator+(const ComplexNumbers& lhs, const ComplexNumbers& rhs);
ComplexNumbers operator-(const ComplexNumbers& lhs, const ComplexNumbers& rhs);
ComplexNumbers operator*(const ComplexNumbers& lhs, const ComplexNumbers& rhs);
ComplexNumbers operator/(const ComplexNumbers& lhs, const ComplexNumbers& rhs);

bool operator==(const ComplexNumbers& lhs, const ComplexNumbers& rhs);
bool operator!=(const ComplexNumbers& lhs, const ComplexNumbers& rhs);


