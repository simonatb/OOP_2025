#pragma once
#include <utility>
#include <exception>
#define TP template<typename T>

namespace constants {
	constexpr size_t DEFAULT_CAPACITY = 8;
	constexpr size_t DEFAULT_SIZE = 0;
}

TP
class Vector {
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize();
	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector<T>&& other) noexcept;
	void free();
public:
	Vector();
	Vector(size_t capacity);
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other) noexcept;
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;
	
	void pushBack(const T& other);
	void pushBack(T&& other) noexcept;
	void pushAt(const T& other, size_t index);
	void pushAt(T&& other, size_t index) noexcept;
	T popBack();
	T popAt(size_t index);

	bool empty() const;
	bool clear();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

};

TP
void Vector<T>::resize() {
	size_t newCapacity = 1;
	while (size > newCapacity) {
		newCapacity <<= 1;
	}
	T* newData = new T[newCapacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

TP
void Vector<T>::copyFrom(const Vector<T>& other) {
	data = new T[other.capacity];
	size = other.size;
	capacity = other.capacity;
	for (size_t i = 0;i < size;i++) {
		data[i] = other.data[i];
	}
}

TP
void Vector<T>::moveFrom(Vector<T>&& other) noexcept {
	data = other.data;
	size = other.size;
	capacity = other.capacity;
	other.size = other.capacity = 0;
}

TP
void Vector<T>::free() {
	delete[] data;
	size = capacity = 0;
}

TP
Vector<T>::Vector() : capacity(constants::DEFAULT_CAPACITY) {}

TP
Vector<T>::Vector(size_t capacity) : capacity(capacity){
	data = new T[capacity];
}

TP
Vector<T>::Vector(const Vector<T>& other) {
	copyFrom(other);
}

TP
Vector<T>::Vector(Vector<T>&& other) noexcept {
	moveFrom(std::move(other));
}

TP
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

TP
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

TP
Vector<T>::~Vector() {
	free();
}

TP
size_t Vector<T>::getSize() const {
	return size;
}

TP
size_t Vector<T>::getCapacity() const {
	return capacity;
}

TP
void Vector<T>::pushBack(const T& other) {
	if (size == capacity) {
		resize();
	}
	data[size++] = other;
}

TP
void Vector<T>::pushBack(T&& other) noexcept {
	if (size == capacity) {
		resize();
	}
	data[size++] = other;
}

TP
void Vector<T>::pushAt(const T& other, size_t index) {
	if (index >= size) {
		throw std::exception("out of range");
	}
	if (size == capacity) {
		resize();
	}
	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}
	data[index] = other;
}

TP
void Vector<T>::pushAt(T&& other, size_t index) noexcept {
	if (index >= size) {
		throw std::exception("out of range");
	}
	if (size == capacity) {
		resize();
	}
	for (size_t i = size; i > index; i--) {
		data[i] = data[i - 1];
	}
	data[index] = std::move(other);
}

TP
T Vector<T>::popBack() {
	if (empty()) {
		throw std::exception("empty");
	}
	return data[--size];
}

TP
T Vector<T>::popAt(size_t index) {
	if (index >= size) {
		throw std::exception("out of range");
	}
	T temp = data[index];
	size--;
	for (size_t i = index; i < size; i++) {
		data[i] = data[i + 1];
	}
	return temp;
}

TP
bool Vector<T>::empty() const {
	return (size == 0);
}

TP
bool Vector<T>::clear() {
	size = 0;
}

TP
T& Vector<T>::operator[](size_t index) {
	if (index >= size) {
		throw std::exception("out of range");
	}
	return data[index];
}

TP
const T& Vector<T>::operator[](size_t index) const {
	if (index >= size) {
		throw std::exception("out of range");
	}
	return data[index];
}
