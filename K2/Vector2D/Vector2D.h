#pragma once
#include <iostream>

class Vector2D {
private:
	double x = 0.0;
	double y = 0.0;
public:
	Vector2D();
	Vector2D(double x, double y);

	double getX() const;
	double getY() const;

	friend Vector2D operator*(double scalar,const Vector2D& vec);
	Vector2D& operator+=(const Vector2D& other);
};

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
bool operator==(const Vector2D& lhs, const Vector2D& rhs);
bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
double operator^(const Vector2D& lhs, const Vector2D& rhs);
