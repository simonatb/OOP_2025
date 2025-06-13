#include "SwapTransformer.h"

namespace helpers {
	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
}

SwapTransformer::SwapTransformer(size_t leftIdx, size_t rightIdx) : leftIdx(leftIdx), rightIdx(rightIdx) {}

void SwapTransformer::transform(int* arr, size_t size) {
	if (leftIdx > size || rightIdx > size) {
		return;
	}
	helpers::swap(arr[leftIdx], arr[rightIdx]);
}

ArrayTransformer* SwapTransformer::clone() const {
	return new SwapTransformer(*this);
}

SwapTransformer::SwapTransformer() {
	leftIdx = rightIdx = 0;
}