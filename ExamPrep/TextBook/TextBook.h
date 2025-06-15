#pragma once
#include "Poem.h"
#include "Question.h"
#include "ArgumentativeText.hpp"

namespace {
	constexpr size_t DEFAULT_CAPACITY = 16;
}

class TextBook {
private:
	Text** texts = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);
	void copyFrom(const TextBook& other);
	void free();
public:
	TextBook(size_t size);
	TextBook(const TextBook& other);
	TextBook& operator=(const TextBook& other);
	~TextBook();

	void addText(Text* ptr);
	void addText(const Text& other);

	friend std::ostream& operator<<(std::ostream& os, const TextBook& other);
};

