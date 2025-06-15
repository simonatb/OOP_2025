#pragma once
#include "Text.h"

constexpr size_t MAX = 1024;

class Question : public Text {
private:
	char answer[MAX+1];
public:
	Question(const char* text, const char* answer);
	void print(std::ostream& os) const override;
	Text* clone() const override;
};

