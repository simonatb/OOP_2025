#include "Vector2D.h"

Vector2D::Vector2D() :x(0), y(0) {}

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::getX() const {
	return x;
}

double Vector2D::getY() const {
	return y;
}

Vector2D operator*(double scalar, const Vector2D& vec) {
	Vector2D copy(vec.getX()*scalar, vec.getY() * scalar);
	return copy;
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
	Vector2D sum(lhs);
	sum += rhs;
	return sum;
}

bool operator==(const Vector2D& lhs, const Vector2D& rhs) {
	return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs) {
	return !(lhs == rhs);
}

double operator^(const Vector2D& lhs, const Vector2D& rhs) {
	return lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY();
}
