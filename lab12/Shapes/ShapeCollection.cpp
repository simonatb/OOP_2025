#include "ShapeCollection.h"

void ShapeCollection::copyFrom(const ShapeCollection& other) {
	shapesCount = other.shapesCount;
	capacity = other.capacity;
	shapes = new Shape*[capacity];
	for (size_t i = 0; i < shapesCount; i++) {
		shapes[i] = other.shapes[i]->clone();
	}
}

void ShapeCollection::moveFrom(ShapeCollection&& other) noexcept {
	shapesCount = other.shapesCount;
	capacity = other.capacity;
	shapes = other.shapes;
	other.shapes = nullptr;
	other.capacity = other.shapesCount = 0;
}

void ShapeCollection::free() {
	for (size_t i = 0; i < shapesCount; i++) {
		delete shapes[i];
	}
	delete[] shapes;
	shapes = nullptr;
	capacity = shapesCount = 0;
}

void ShapeCollection::resize() {
	Shape** temp = new Shape * [capacity * 2];
	for (size_t i = 0; i < shapesCount; i++) {
		temp[i] = shapes[i];
	}
	delete[] shapes;
	shapes = temp;
	capacity *= 2;
}

ShapeCollection::ShapeCollection() {
	capacity = constants::DEFAULT_CAPACITY;
	shapesCount = 0;
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other) {
	copyFrom(other);
}

ShapeCollection::ShapeCollection(ShapeCollection&& other) noexcept {
	moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other) noexcept {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ShapeCollection::~ShapeCollection() noexcept {
	free();
}

void ShapeCollection::addFigure(Shape* shape) {
	if (shapesCount == capacity) {
		resize();
	}
	shapes[shapesCount++] = shape;
	shape = nullptr;
}

void ShapeCollection::addFigure(const Shape& shape) {
	Shape* cloned = shape.clone();
	addFigure(cloned);
}

double ShapeCollection::getAreaByIndex(unsigned ind) const {
	if (ind > shapesCount) {
		throw std::logic_error("index is out of bounds");
	}
	return shapes[ind]->getArea();
}

double ShapeCollection::getPerByIndex(unsigned ind) const {
	if (ind > shapesCount) {
		throw std::logic_error("index is out of bounds");
	}
	return shapes[ind]->getPer();
}

double ShapeCollection::getIsPointInByIndex(unsigned ind, int x, int y) const {
	if (ind > shapesCount) {
		throw std::logic_error("index is out of bounds");
	}
	return shapes[ind]->isPointIn(x,y);
}

const Shape* ShapeCollection::operator[](unsigned ind) const {
	if (ind > shapesCount) {
		throw std::logic_error("index is out of bounds");
	}
	return shapes[ind];
}

unsigned ShapeCollection::getSize() const {
	return shapesCount;
}