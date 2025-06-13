#pragma once
#include <exception>
#include "EventBase.hpp"
#include "LogEvent.hpp"
#include "MetricEvent.hpp"
#include "AlarmEvent.hpp"

template <const size_t capacity>
class EventContainer {
public:
	EventBase** events = nullptr;
	size_t size = 0;

	void copyFrom(const EventContainer& other);
	void moveFrom(EventContainer&& other) noexcept;
	void free();
public:
	EventContainer();
	EventContainer(const EventContainer& other);
	EventContainer(EventContainer&& other) noexcept;
	EventContainer& operator=(const EventContainer& other);
	EventContainer& operator=(EventContainer&& other) noexcept;
	~EventContainer();

	void add(const EventBase& event);
	void pop();
	void printAll() const;

};

template <const size_t capacity>
void EventContainer<capacity>::copyFrom(const EventContainer& other) {
	size = other.size;
	events = new EventBase*[capacity];
	for (size_t i = 0; i < size; i++) {
		events[i] = other.events[i]->clone();
	}
}

template <const size_t capacity>
void EventContainer<capacity>::moveFrom(EventContainer&& other) noexcept {
	events = other.events;
	other.events = nullptr;
	size = other.size;
	other.size = 0;
}

template <const size_t capacity>
void EventContainer<capacity>::free() {
	for (size_t i = 0; i < size; i++) {
		delete events[i];
	}
	delete[] events;
	events = nullptr;
	size = 0;
}


template <const size_t capacity>
EventContainer<capacity>::EventContainer() : events(new EventBase*[capacity]), size(0) {}

template <const size_t capacity>
EventContainer<capacity>::EventContainer(const EventContainer& other) {
	copyFrom(other);
}
template <const size_t capacity>
EventContainer<capacity>::EventContainer(EventContainer&& other) noexcept {
	moveFrom(std::move(other));
}

template <const size_t capacity>
EventContainer<capacity>& EventContainer<capacity>::operator=(const EventContainer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <const size_t capacity>
EventContainer<capacity>& EventContainer<capacity>::operator=(EventContainer&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <const size_t capacity>
EventContainer<capacity>::~EventContainer() {
	free();
}

template <const size_t capacity>
void EventContainer<capacity>::add(const EventBase& event) {
	if (size == capacity) {
		throw std::out_of_range("max capacity");
	}
	events[size++] = event.clone();
}

template <const size_t capacity>
void EventContainer<capacity>::pop() {
	if (size == 0) {
		throw std::out_of_range("no elements");
	}
	size--;
}

template <const size_t capacity>
void EventContainer<capacity>::printAll() const {
	for (size_t i = 0;i < size; i++) {
		events[i]->print();
		cout << "Serialized: " << events[i]->serialize() << endl;
	}
}