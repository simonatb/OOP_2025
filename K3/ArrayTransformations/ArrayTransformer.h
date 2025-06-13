#pragma once
#include <exception>

namespace {
	constexpr size_t DEFAULT_CAPACITY = 8;
	constexpr size_t DEFAULT_COUNT = 0;
}

enum class Transformer {
	criteria,
	replace,
	scalar,
	swap
};

class ArrayTransformer {
public:
	virtual ~ArrayTransformer() = default;
	virtual void transform(int* arr, size_t size) = 0;
	virtual ArrayTransformer* clone() const = 0;
};

