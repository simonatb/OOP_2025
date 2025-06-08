#pragma once
#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

namespace constants {
	constexpr size_t DEFAULT_CAPACITY = 8;
}

class ShapeCollection {
private:
	Shape** shapes;
	size_t shapesCount;
	size_t capacity;

	void copyFrom(const ShapeCollection& other);
	void moveFrom(ShapeCollection&& other) noexcept;
	void free();
	void resize();
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection(ShapeCollection&& other) noexcept;
	ShapeCollection& operator=(const ShapeCollection& other);
	ShapeCollection& operator=(ShapeCollection&& other) noexcept;
	~ShapeCollection() noexcept;

	void addFigure(Shape* shape);
	void addFigure(const Shape& shape);

	double getAreaByIndex(unsigned ind) const;
	double getPerByIndex(unsigned ind) const;
	double getIsPointInByIndex(unsigned ind, int x, int y) const;

	const Shape* operator[](unsigned) const;
	unsigned getSize() const;
};

