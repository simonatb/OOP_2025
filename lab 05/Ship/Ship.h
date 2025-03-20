#pragma once
 
namespace CONSTS {
	constexpr int NAME_SIZE = 10;
	constexpr int YEAR = 20250;
	constexpr int GUN_COUNT = 0;
}
 
enum class ShipClass {
	battleship,
	battlecruiser
};
 
class Ship{
private:
	char* name = nullptr;
	int launched;
	ShipClass shipClass;
	int gunCount;
 
	void copyFrom(const Ship& other);
	void free();
 
public:
	Ship();
	Ship(const Ship& other);
	Ship& operator=(const Ship& other);
	~Ship();
 
	void setName(const char* newName);
	void setYear(int year);
	void setClass(ShipClass shipClass);
	void setGunCount(int newCount);
 
	const char* getName() const;
	const int getYear() const;
	const ShipClass getClass() const;
	const int getGunCount() const;
 
};
