#pragma once
#include "ArrayTransformer.h"
#define TP template <typename T>

TP
class CriteriaTransformer : public ArrayTransformer {
public:
	void transform(int* arr, size_t size) override;
	bool operator()(int number) const;
	ArrayTransformer* clone() const override;
};

