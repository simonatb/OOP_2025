#include "ScalarTransformer.h"

ScalarTransformer::ScalarTransformer(int number) {
	scalar = number;
}

void ScalarTransformer::transform(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		arr[i] *= scalar;
	}
}

ArrayTransformer* ScalarTransformer::clone() const {
	return new ScalarTransformer(*this);
}

ScalarTransformer::ScalarTransformer() {
	scalar = 0;
}