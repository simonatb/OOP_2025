#pragma once
#include "ArrayTransformer.h"
#include "ArrayFactory.h"

class Transformers {
private:
	ArrayTransformer** transformers = nullptr;
	size_t count;
	size_t capacity;

	void copyFrom(const Transformers& other);
	void moveFrom(Transformers&& other) noexcept;
	void free();

	void resize();
public:
	Transformers();
	Transformers(size_t capacity);
	Transformers(const Transformers& other);
	Transformers(Transformers&& other) noexcept;
	Transformers& operator=(const Transformers& other);
	Transformers& operator=(Transformers&& other) noexcept;
	~Transformers();


	void add(Transformer type);
	void allTransformations(int* arr, size_t size);
	void transformationInterval(int* arr, size_t size, size_t begin, size_t end);
	Transformer slice(size_t begin, size_t end);
};

