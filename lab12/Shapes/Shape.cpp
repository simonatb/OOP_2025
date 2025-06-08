#pragma once
#include "Shape.h"

void Shape::copyFrom(const Shape& other) {
	points = new Point[other.pointsCount];
	pointsCount = other.pointsCount;
	for (size_t i = 0; i < pointsCount;i++) {
		points[i] = other.points[i];
	}
}

void Shape::moveFrom(Shape&& other) noexcept {
	points = other.points;
	other.points = nullptr;
	pointsCount = other.pointsCount;
	other.pointsCount = 0;
}

void Shape::free() {
	delete[] points;
	points = nullptr;
	pointsCount = 0;
}

Shape::Shape(size_t pointsCount) {
	points = new Point[pointsCount];
}

Shape::Shape(const Shape& other) {
	copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept {
	moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Shape& Shape::operator=(Shape&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Shape::~Shape() {
	free();
}

void Shape::setPoint(size_t index, int x, int y) {
	if (index > pointsCount) {
		throw std::exception("invalid index");
	}
	points[index] = Point(x, y);
}

double Shape::getPer() const {
	double per = 0;
	for (size_t i = 0;i < pointsCount - 1;i++) {
		per += points[i].getDist(points[i + 1]);
	}
	return per + points[pointsCount - 1].getDist(points[0]);
}

const Shape::Point& Shape::getPointAtIndex(size_t index) const {
	if (index > pointsCount) {
		throw std::exception("invalid index");
	}
	return points[index];
}