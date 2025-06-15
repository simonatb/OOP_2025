#include "Farm.h"

void Farm::copyFrom(const Farm& other) {
	farm = new Animal * [other.capacity];
	for (size_t i = 0;i < other.count; i++) {
		farm[i] = other.farm[i]->clone();
	}
	count = other.count;
	capacity = other.capacity;
}

void Farm::moveFrom(Farm&& other) noexcept {
	farm = other.farm;
	other.farm = nullptr;
	count = other.count;
	capacity = other.capacity;
	other.count = other.capacity = 0;
}

void Farm::free() {
	for (size_t i = 0;i < count;i++) {
		delete farm[i];
	}
	delete[] farm;
}

Farm::Farm() {
	capacity = 8;
	farm = new Animal * [capacity] {nullptr};
}
Farm::Farm(const Farm& other) {
	copyFrom(other);
}
Farm::Farm(Farm&& other) noexcept {
	moveFrom(std::move(other));
}
Farm& Farm::operator=(const Farm& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Farm& Farm::operator=(Farm&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Farm::~Farm() {
	free();
}

void Farm::addAnimal(Animal* animal) {
	if (!animal) {
		return;
	}
	if (count == capacity) {
		resize();
	}
	farm[count++] = animal;
}

void Farm::addAnimal(const Animal& animal) {
	if (!animal) {
		return;
	}
	if (count == capacity) {
		resize();
	}
	farm[count++] = animal->clone();
}

void Farm::resize() {
	Animal** arr = new Animal * [capacity * 2];
	for (size_t i = 0;i < count;i++) {
		arr[i] = farm[i];
	}
	delete[] farm;
	farm = arr;
	arr = nullptr;
}

void Farm::roarAll() const {
	for (size_t i = 0;i < count;i++) {
		farm[i]->sound();
	}
}
