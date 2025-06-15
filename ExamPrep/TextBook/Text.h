#pragma once
#include <iostream>

class Text {
private:
	char* text;
	unsigned ID = 0;
	static unsigned IDCounter;

	void copyFrom(const Text& other);
	void free();
public:
	Text(const char* str);
	Text(const Text& other);
	Text& operator=(const Text& other);
	virtual ~Text();

	static unsigned getNextId();
	const char& operator[](size_t index) const;
	unsigned getID() const;
	const char* getText() const;

	virtual void print(std::ostream& os) const = 0;
	virtual Text* clone() const = 0;
};