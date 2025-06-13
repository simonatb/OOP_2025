#pragma once
#include "ArrayTransformer.h"

class ScalarTransformer : virtual public ArrayTransformer {
private:
	int scalar = 0;
public:
	ScalarTransformer();
	ScalarTransformer(int number);
	void transform(int* arr, size_t size) override;
	ArrayTransformer* clone() const override;
};

