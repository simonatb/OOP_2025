#pragma once
#include "Text.h"
class Poem : public Text {
private:
	char** keys = nullptr;
	size_t count = 0;

	void copyFrom(const Poem& other);
	void free();
public:
	Poem(size_t count, const char* text);
	Poem(const Poem& other);
	Poem& operator=(const Poem& other);
	~Poem();

	void print(std::ostream& os) const override;
};

