#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers(): real(0),im(0) {}

ComplexNumbers::ComplexNumbers(double real, double im) : real(real), im(im) {}

double ComplexNumbers::getReal() const {
	return real;
}

double ComplexNumbers::getIm() const {
	return im;
}

void ComplexNumbers::setReal(double real) {
	this->real = real;
}

void ComplexNumbers::setIm(double im) {
	this->im = im;
}

ComplexNumbers ComplexNumbers::getConjugated() const {
	ComplexNumbers result(*this);
	result.im *= -1;
	return result;
}

ComplexNumbers& ComplexNumbers::operator+=(const ComplexNumbers& other) {
	real += other.real;
	im += other.im;
	return *this;
}

ComplexNumbers& ComplexNumbers::operator-=(const ComplexNumbers& other) {
	real -= other.real;
	im -= other.im;
	return *this;
}

ComplexNumbers& ComplexNumbers::operator*=(const ComplexNumbers& other) {
	real = (real * other.real) - (im * other.im);
	im = (real * other.im) + (im * other.real);
	return *this;
}

ComplexNumbers& ComplexNumbers::operator/=(const ComplexNumbers& other) {
	ComplexNumbers Conjugated = other.getConjugated(); //взимаме комплексно спрегнатата на другата дроб (b)

	ComplexNumbers otherCopy(other);// копираме другата (b), за да не я промяняме.

	//Умножаваме двете по комплексно спрегнатата.
	*this *= Conjugated;
	otherCopy *= Conjugated; //Тук трябва да остане само реална част.

	if (otherCopy.real != 0)
	{
		real /= otherCopy.real;
		im /= otherCopy.real;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumbers& other) {
	return os << other.real << " " << other.im << " i";
}

std::istream& operator>>(std::istream& is, ComplexNumbers& other) {
	return is >> other.real >> other.im;
}

ComplexNumbers operator+(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	ComplexNumbers copy(lhs);
	copy += rhs;
	return copy;
}

ComplexNumbers operator-(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	ComplexNumbers copy(lhs);
	copy -= rhs;
	return copy;
}

ComplexNumbers operator*(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	ComplexNumbers copy(lhs);
	copy *= rhs;
	return copy;
}

ComplexNumbers operator/(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	ComplexNumbers copy(lhs);
	copy /= rhs;
	return copy;
}

bool operator==(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const ComplexNumbers& lhs, const ComplexNumbers& rhs) {
	return !(lhs == rhs);
}
