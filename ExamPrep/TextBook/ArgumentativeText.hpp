#pragma once
#include "Text.h"
#define TP template <typename T>

TP
class ArgumentativeText : public Text {
private:
	T criteria;
	size_t l1, l2, l3, l4;

	void printParagraph(std::ostream& os, size_t beg, size_t end) const;
public:
	ArgumentativeText(const T& criteria, const char* text, size_t l1, size_t l2, size_t l3, size_t l4);
	void print(std::ostream& os) const override;
	Text* clone() const override;
};

TP
ArgumentativeText<T>::ArgumentativeText(const T& criteria, const char* text, size_t l1, size_t l2, size_t l3, size_t l4) : Text(text) , criteria(criteria), l1(l1), l2(l2), l3(l3), l4(l4) {}

TP
void ArgumentativeText<T>::print(std::ostream& os) const {
	printParagraph(os, 0, l1);
	printParagraph(os, l1, l1+l2);
	printParagraph(os, l1 + l2, l1 + l2 + l3);
	printParagraph(os, l1 + l2 + l3, l1 + l2 + l3 + l4);

	bool isValid = criteria(text);

	if (isValid)
	{
		os << "Valid ArgumentText" << "\n";
	}
	else
	{
		os << "Invalid ArgumentText" << "\n";
	}
}

TP
void ArgumentativeText<T>::printParagraph(std::ostream& os, size_t beg, size_t end) const {
	for (size_t i = beg; i < end; i++) {
		os << text[i];
	}
	os << "\n";
}

TP
Text* ArgumentativeText<T>::clone() const {
	return new ArgumentativeText(*this);
}