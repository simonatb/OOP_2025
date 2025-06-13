#pragma once
#include "ArrayTransformer.h"

class SwapTransformer : virtual public ArrayTransformer {
private:
	size_t leftIdx = 0;
	size_t rightIdx = 0;
public:
	SwapTransformer();
	SwapTransformer(size_t leftIdx, size_t rightIdx);
	void transform(int* arr, size_t size) override;
	ArrayTransformer* clone() const override;
};

