#include "TextBook.h"

void TextBook::copyFrom(const TextBook& other)
{
	texts = new Text * [other.capacity];
	size = other.size;
	capacity = other.capacity;
	for (size_t i = 0; i < size; i++) {
		texts[i] = other.texts[i]->clone();
	}
}

void TextBook::free()
{
	for (size_t i = 0; i < size; i++) {
		delete texts[i];
	}
	delete[] texts;
	texts = nullptr;
	size = capacity = 0;
}

void TextBook::resize(size_t newCapacity) {
	Text** temp = new Text * [newCapacity];
	capacity = newCapacity;
	for (size_t i = 0; i < size; i++) {
		temp[i] = texts[i];
	}
	delete[] texts;
	texts = temp;
}

TextBook::TextBook(size_t capacity) : size(0) , capacity(capacity)
{
	texts = new Text * [capacity] {nullptr};
}

TextBook::TextBook(const TextBook& other)
{
	copyFrom(other);
}

TextBook& TextBook::operator=(const TextBook& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

TextBook::~TextBook()
{
	free();
}

void TextBook::addText(Text* ptr)
{
	if (size == capacity) {
		resize(capacity + DEFAULT_CAPACITY);
	}
	texts[size++] = ptr;
}

void TextBook::addText(const Text& other)
{
	if (size == capacity) {
		resize(capacity + DEFAULT_CAPACITY);
	}
	texts[size++] = other.clone();
}

std::ostream& operator<<(std::ostream& os, const TextBook& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		other.texts[i]->print(os);
		os << '\n';
	}
	return os;
}
