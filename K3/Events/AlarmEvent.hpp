#pragma once
#include "Event.hpp"

TP
class AlarmEvent : public Event<T> {
public:
	AlarmEvent(const T& data);
	void print() const override;
	MyString serialize() const override;
	EventBase* clone() const override;
};

TP
AlarmEvent<T>::AlarmEvent(const T& data) : Event<T>(data) {}

TP
void AlarmEvent<T>::print() const {
	std::cout << "Alarm: " << payload << std::endl;
}

TP
MyString AlarmEvent<T>::serialize() const {
	std::ostringstream oss;
	oss << "Alarm=<" << payload << ">";
	return oss.str().c_str();
}

TP
EventBase* AlarmEvent<T>::clone() const {
	return new AlarmEvent(*this);
}
