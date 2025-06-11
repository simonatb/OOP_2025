#include "Tpeak.h"

void Tpeak::copyFrom(const Tpeak& other) {
	setMount(other.getMount());
}

void Tpeak::free() {
	delete[] mount;
	mount = nullptr;
}

Tpeak::Tpeak() : Peak() {
	setMount(STRING);
}

Tpeak::Tpeak(const char* mountain, int height, const char* mount) : Peak(mountain, height) {
	setMount(mount);
}

Tpeak::Tpeak(const Tpeak& other) : Peak(other) {
	copyFrom(other);
}

Tpeak& Tpeak::operator=(const Tpeak& other) {
	if (this != &other) {
		free();
		copyFrom(other);
		Peak::operator=(other);
	}
	return *this;
}

Tpeak::~Tpeak() {
	free();
}

void Tpeak::setMount(const char* mount) {
	if (!mount || this->mount == mount) {
		return;
	}
	if (this->mount) {
		delete[] this->mount;
	}
	this->mount = new char[strlen(mount) + 1];
	strcpy(this->mount, mount);
}

const char* Tpeak::getMount() const {
	return mount;
}

void Tpeak::printPeakName() const {
	std::cout << mount << std::endl;
}