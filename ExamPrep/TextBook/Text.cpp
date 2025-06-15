#include "Text.h"

unsigned Text::IDCounter = 0;

void Text::copyFrom(const Text& other)
{
	text = new char[strlen(other.text) + 1];
	strcpy(text, other.text);
	this->ID = IDCounter++;
}

void Text::free()
{
	delete[] text;
	text = nullptr;
	ID = 0;
}

Text::Text(const char* str)
{
	text = new char[strlen(str) + 1];
	strcpy(text, str);
	ID = IDCounter++;
}

Text::Text(const Text& other)
{
	copyFrom(other);
}

Text& Text::operator=(const Text& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Text::~Text()
{
	free();
}

const char& Text::operator[](size_t index) const {
	return text[index];
}

unsigned Text::getNextId()
{
	return IDCounter;
}

const char* Text::getText() const {
	return text;
}

unsigned Text::getID() const
{
	return ID;
}

void Text::print(std::ostream& os) const
{
}


