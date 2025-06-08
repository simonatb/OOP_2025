#include "Circle.h"

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius) {
	setPoint(0, x, y);
}

double Circle::getArea() const {
	return constants::PI * radius * radius;
}

double Circle::getPer() const {
	return constants::PI * radius * 2;
}

bool Circle::isPointIn(int x, int y) const {
	Shape::Point p(x, y);
	return p.getDist(getPointAtIndex(0)) <= radius;
}

Shape* Circle::clone() const {
	return new Circle(*this);
}