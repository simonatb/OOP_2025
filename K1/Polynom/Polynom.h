#pragma once
class Polynom
{
private:
	double* data;
	size_t n;

	void free();
	void copyFrom(const Polynom& other);
	void copyArray(const double* source, double* dest, size_t size);
	void resize(size_t newSize);

public:
	Polynom(size_t n);
	Polynom(const Polynom& other);
	Polynom& operator=(const Polynom& other);
	~Polynom();
	void load(const char* filename);
	void print() const;
	void add(const Polynom& other);
};
