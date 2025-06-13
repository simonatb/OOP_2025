#include "Transformers.h"

void Transformers::copyFrom(const Transformers& other) {
	count = other.count;
	capacity = other.capacity;
	transformers = new ArrayTransformer * [capacity];
	for (size_t i = 0; i < count; i++) {
		transformers[i] = other.transformers[i];
	}
}

void Transformers::moveFrom(Transformers&& other) noexcept {
	count = other.count;
	capacity = other.capacity;
	transformers = other.transformers;
	other.count = other.capacity = 0;
	other.transformers = nullptr;
}

void Transformers::free() {
	for (size_t i = 0; i < count; i++) {
		delete[] transformers[i];
	}
	delete[] transformers;
	transformers = nullptr;
	count = capacity = 0;
}

void Transformers::resize() {
	capacity *= 2;
	ArrayTransformer** newTransformers = new ArrayTransformer * [capacity];
	for (size_t i = 0; i < count; i++) {
		newTransformers[i] = transformers[i];
	}
	delete[] transformers;
	transformers = newTransformers;
}

Transformers::Transformers() : count(DEFAULT_COUNT), capacity(DEFAULT_CAPACITY) {
	transformers = new ArrayTransformer * [capacity];
}

Transformers::Transformers(size_t capacity) : count(DEFAULT_COUNT), capacity(capacity) {
	transformers = new ArrayTransformer * [capacity];
}

Transformers::Transformers(const Transformers& other) {
	copyFrom(other);
}

Transformers::Transformers(Transformers&& other) noexcept {
	moveFrom(std::move(other));
}

Transformers& Transformers::operator=(const Transformers& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Transformers& Transformers::operator=(Transformers&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Transformers::~Transformers() {
	free();
}


void Transformers::add(Transformer type) {
	if (count == capacity) {
		resize();
	}
	transformers[count++] = arrayFactory(type);
}

void Transformers::allTransformations(int* arr, size_t size) {
	for (size_t i = 0;i < count; i++) {
		transformers[i]->transform(arr, size);
	}
}

void Transformers::transformationInterval(int* arr, size_t size, size_t begin, size_t end) {
	if (begin < count || end < count) {
		throw std::exception("error");
	}
	for (size_t i = begin;i < end; i++) {
		transformers[i]->transform(arr, size);
	}
}

Transformer Transformers::slice(size_t begin, size_t end) {
	if (begin < count || end < count) {
		throw std::exception("error");
	}
	size_t newCapacity = end - begin;
	Transformers result(end - begin);
	for (size_t i = 0; i < newCapacity; i++) {
		result.transformers[i] = transformers[begin + i]->clone();
	}

}