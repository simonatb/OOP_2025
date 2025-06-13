#include "ReplaceTransformer.h"

void ReplaceTransformer::copyFrom(const ReplaceTransformer& other) {
	pairs = new Pair[other.pairsCount];
	pairsCount = other.pairsCount;
	for (size_t i = 0; i < pairsCount; i++) {
		pairs[i] = other.pairs[i];
	}
}

void ReplaceTransformer::moveFrom(ReplaceTransformer&& other) noexcept {
	pairs = other.pairs;
	other.pairs = nullptr;
	pairsCount = other.pairsCount;
	other.pairsCount = 0;
}

void ReplaceTransformer::free() {
	delete[] pairs;
	pairs = nullptr;
	pairsCount = 0;
}

ReplaceTransformer::ReplaceTransformer(const Pair* pairs, size_t count) {
	this->pairs = new Pair[count];
	this->pairsCount = count;
	for (size_t i = 0; i < pairsCount; i++) {
		this->pairs[i] = pairs[i];
	}
}

ReplaceTransformer::ReplaceTransformer(const ReplaceTransformer& other) : ArrayTransformer(other) {
	copyFrom(other);
}

ReplaceTransformer::ReplaceTransformer(ReplaceTransformer&& other) noexcept : ArrayTransformer(std::move(other)) {
	moveFrom(std::move(other));
}

ReplaceTransformer& ReplaceTransformer::operator=(const ReplaceTransformer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
		ArrayTransformer::operator=(other);
	}
	return *this;
}

ReplaceTransformer& ReplaceTransformer::operator=(ReplaceTransformer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
		ArrayTransformer::operator=(std::move(other));
	}
	return *this;
}

ReplaceTransformer::~ReplaceTransformer() {
	free();
}

void ReplaceTransformer::transform(int* arr, size_t size) {
	for (size_t i = 0;i < pairsCount;i++) {
		if (pairs[i].idx >= size) {
			continue;
		}
		arr[pairs[i].idx] = pairs[i].number;
	}
}

ArrayTransformer* ReplaceTransformer::clone() const {
	return new ReplaceTransformer(*this);
}

ReplaceTransformer::ReplaceTransformer() : pairsCount(DEFAULT_CAPACITY) {
	pairs = new Pair[pairsCount];
}