#pragma once
#include "Peak.h"

class Tpeak : virtual public Peak {
private:
	char* mount;

	void copyFrom(const Tpeak& other);
	void free();
public:
	Tpeak();
	Tpeak(const char* mountain, int height, const char* mount);
	Tpeak(const Tpeak& other);
	Tpeak& operator=(const Tpeak& other);
	~Tpeak();

	void setMount(const char* mount);
	const char* getMount() const;
};

