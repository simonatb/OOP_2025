#include "Ship.h"
#include <cstring>
 
#pragma warning (disable : 4996)
 
void Ship::copyFrom(const Ship& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	launched = other.launched;
	gunCount = other.gunCount;
	shipClass = other.shipClass;
}
 
void Ship::free() {
	delete[] name;
	name = nullptr;
	launched = gunCount = 0;
}
 
Ship::Ship() {
	name = new char[CONSTS::NAME_SIZE + 1];
	launched = CONSTS::YEAR;
	shipClass = ShipClass::battleship;
	gunCount = CONSTS::GUN_COUNT;
}
 
Ship::Ship(const Ship& other) {
	copyFrom(other);
}
 
Ship& Ship::operator=(const Ship& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
 
Ship::~Ship() {
	free();
}
 
void Ship::setName(const char* newName) {
	if (!newName || newName == name) {
		return;
	}
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}
 
void Ship::setYear(int year) {
	launched = year;
}
 
void Ship::setClass(ShipClass shipClass) {
	this->shipClass = shipClass;
}
 
void Ship::setGunCount(int newCount) {
	gunCount = newCount;
}
 
const char* Ship::getName() const {
	return name;
}
 
const int Ship::getYear() const {
	return launched;
}
 
const ShipClass Ship::getClass() const {
	return shipClass;
}
 
const int Ship::getGunCount() const {
	return gunCount;
}
