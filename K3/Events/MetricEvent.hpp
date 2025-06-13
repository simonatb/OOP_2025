#pragma once
#include "Event.hpp"

TP
class MetricEvent : public Event<T> {
public:
	MetricEvent(const T& data);
	void print() const override;
	MyString serialize() const override;
	EventBase* clone() const override;
};

TP
MetricEvent<T>::MetricEvent(const T& data) : Event<T>(data) {}

TP
void MetricEvent<T>::print() const {
	std::cout << "Metric: " << payload << std::endl;
}

TP
MyString MetricEvent<T>::serialize() const {
	std::ostringstream oss;
	oss << "Metric=<" << payload << ">";
	return oss.str().c_str();
}

TP
EventBase* MetricEvent<T>::clone() const {
	return new MetricEvent(*this);
}
