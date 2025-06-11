#include "Peak.h"

void Peak::copyFrom(const Peak& other) {
	mountain = new char[strlen(other.mountain) + 1];
	strcpy(mountain, other.mountain);
	height = other.height;
}

void Peak::free() {
	delete[] mountain;
	mountain = nullptr;
	height = 0;
}

Peak::Peak() : Peak(STRING, HEIGHT) {}

Peak::Peak(const char* name, int height) {
	setMountain(name);
	setHeight(height);
}

Peak::Peak(const Peak& other) {
	copyFrom(other);
}

Peak& Peak::operator=(const Peak& other) {
	if(this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Peak::~Peak() {
	free();
}

void Peak::setMountain(const char* name) {
	delete[] mountain;
	mountain = new char[strlen(name) + 1];
	strcpy(mountain, name);
}

const char* Peak::getMountain() const {
	return mountain;
}
	
void Peak::setHeight(int height) {
	this->height = height;
}
	
int Peak::getHeight() const {
	return height;
}