#pragma once
#include "ArrayTransformer.h"

struct Pair {
	size_t idx;
	int number;
};

class ReplaceTransformer : public ArrayTransformer {
private:
	Pair* pairs;
	size_t pairsCount;

	void copyFrom(const ReplaceTransformer& other);
	void moveFrom(ReplaceTransformer&& other) noexcept;
	void free();
public:
	ReplaceTransformer();
	ReplaceTransformer(const Pair* pairs, size_t count);
	ReplaceTransformer(const ReplaceTransformer& other);
	ReplaceTransformer(ReplaceTransformer&& other) noexcept;
	ReplaceTransformer& operator=(const ReplaceTransformer& other);
	ReplaceTransformer& operator=(ReplaceTransformer&& other) noexcept;
	~ReplaceTransformer();

	ArrayTransformer* clone() const override;
	void transform(int* arr, size_t size) override;
};

