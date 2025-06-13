#pragma once
#include <iostream>
#include <fstream>
#include "EventBase.hpp"
#include "MyString.h"
#define TP template<typename T>

TP
class Event : public virtual EventBase {
private:
	T payload;
public:
	const T& getPayload() const;
	Event(const T& data);
	void print() const override;
	MyString serialize() const override;
	EventBase* clone() const override;
};

TP
Event<T>::Event(const T& data) : payload(data) {}

TP
MyString Event<T>::serialize() const {
	std::ostringstream oss;
	oss << payload;
	return oss.str().c_str();
}

TP
void Event<T>::print() const {
	std::cout << "Event: " << payload <<std::endl;
}

TP
EventBase* Event<T>::clone() const {
	return new Event<T>(*this);
}

TP
const T& Event<T>::getPayload() const {
	return payload;
}

template <>
class Event<MyString> : public virtual EventBase {
protected:
	MyString payload;
public:
	const MyString& getPayload() const;
	Event(const MyString& data);
	void print() const override;
	MyString serialize() const override;
	EventBase* clone() const override;
};

Event<MyString>::Event(const MyString& data) : payload(data) {}

void Event<MyString>::print() const {
	std::cout << "Event: \"" << payload << "\"" << std::endl;
}

MyString Event<MyString>::serialize() const {
	return "\"" + payload + "\"";
}

EventBase* Event<MyString>::clone() const {
	return new Event<MyString>(*this);
}

const MyString& Event<MyString>::getPayload() const {
	return payload;
}