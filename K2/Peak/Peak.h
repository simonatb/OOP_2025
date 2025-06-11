#pragma once
#include <iostream>

constexpr char STRING[] = "none";
constexpr int HEIGHT = 0;

class Peak {
private:
	char* mountain;
	int height;

	void copyFrom(const Peak& other);
	void free();
public:
	Peak();
	Peak(const char* name, int height);
	Peak(const Peak& other);
	Peak& operator=(const Peak& other);
	virtual ~Peak();

	void setMountain(const char* name);
	const char* getMountain() const;

	void setHeight(int height);
	int getHeight() const;
};

