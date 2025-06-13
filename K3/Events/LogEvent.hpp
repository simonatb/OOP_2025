#pragma once
#include "Event.hpp"

TP
class LogEvent : public Event<T> {
public:
	LogEvent(const T& data);
	void print() const override;
	MyString serialize() const override;
	EventBase* clone() const override;
};

TP 
LogEvent<T>::LogEvent(const T& data) : Event<T>(data) {}

TP
void LogEvent<T>::print() const {
	std::cout << "Log: " << payload << std::endl;
}

TP
MyString LogEvent<T>::serialize() const {
	std::ostringstream oss;
	oss << "Log=<" << payload <<">";
	return oss.str().c_str();
}

TP
EventBase* LogEvent<T>::clone() const {
	return new LogEvent(*this);
}
