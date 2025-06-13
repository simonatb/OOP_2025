#include "CriteriaTransformer.h"

TP
void CriteriaTransformer<T>::transform(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (!CriteriaTransformer::operator(arr[i])) {
			arr[i] = -1;
		}
	}
}

TP
bool CriteriaTransformer<T>::operator()(int number) const {

}

TP
ArrayTransformer* CriteriaTransformer<T>::clone() const {
	return new CriteriaTransformer(*this);
}