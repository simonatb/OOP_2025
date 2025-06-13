#pragma once
#include "MyString.h"

class EventBase {
public:
	virtual void print() const = 0;
	virtual MyString serialize() const = 0;
	virtual EventBase* clone() const = 0;
	virtual ~EventBase() = default;
};