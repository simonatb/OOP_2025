#pragma once
#include <iostream>
using namespace std;

namespace {
	constexpr int MIN = 0;
	constexpr int HOURS = 24;
	constexpr int MINUTES = 60;
	constexpr int SECONDS = 60;
}

class Time
{
private:

	size_t hours, minutes, seconds;

public:
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(size_t _hours, size_t _minutes, size_t _seconds) {
		setHours(_hours);
		setMinutes(_minutes);
		setSeconds(_seconds);
	}
	void timeLeftToMidnight() const {
		cout << (HOURS - hours) << ":";
		cout << (MINUTES - minutes) << ":";
		cout << (SECONDS - seconds) << " time left to midnight\n";
	}

	void plusSecond() {
		size_t currentSeconds = seconds + 1;
		if (currentSeconds >= SECONDS) {
			seconds -= SECONDS;
			minutes++;
			if (minutes >= MINUTES) {
				hours++;
				minutes -= MINUTES;
				if (hours >= HOURS) {
					hours -= HOURS;
				}
			}
		}
	}
	bool dinnerTime() const {
		size_t current = calculateSeconds(hours, minutes, seconds);
		size_t begin = calculateSeconds(20, 30, 0);
		size_t end = calculateSeconds(22, 0, 0);
		return (current >= begin && current <= end);
	}
	bool partyTime() const {
		size_t current = calculateSeconds(hours, minutes, seconds);
		size_t begin = calculateSeconds(23, 00, 0);
		size_t end = calculateSeconds(6, 0, 0);
		return (current >= begin || current <= end);
	}
	Time& intersection(const Time& other) {
		size_t hoursDiff = abs(other.hours, hours);
		size_t minutesDiff = abs(other.minutes, minutes);
		size_t secondsDiff = abs(other.seconds, seconds);

		Time newTime(hoursDiff, minutesDiff, secondsDiff);
		return newTime;
	}
	bool comparison(const Time& other) const {
		//if this < other 1
		//else 0
		size_t current = calculateSeconds(hours, minutes, seconds);
		size_t otherSeconds = calculateSeconds(other.hours, other.minutes, other.seconds);

		return (current < otherSeconds);
	}
	void print() const {
		cout << hours << ":" << minutes << ":" << seconds << "\n";
	}

	void setHours(size_t _hours) {
		if (_hours < MIN || _hours > HOURS) {
			hours = MIN;
		}
		else {
			hours = _hours;
		}
	}
	void setMinutes(size_t _minutes) {
		if (_minutes < MIN || _minutes > MINUTES) {
			minutes = MIN;
		}
		else {
			minutes = _minutes;
		}
	}
	void setSeconds(size_t _seconds) {
		if (_seconds < MIN || _seconds > SECONDS) {
			seconds = MIN;
		}
		else {
			seconds = _seconds;
		}
	}

	//helper function
	size_t calculateSeconds(size_t h, size_t m, size_t s) const{
		size_t totalSeconds = h * (SECONDS * MINUTES);
		totalSeconds += m * SECONDS;
		totalSeconds += s;
		return totalSeconds;
	}

	size_t abs(size_t n1, size_t n2) {
		size_t diff = n1 - n2;
		if (diff < 0) {
			return -diff;
		}
		return diff;
	}
	
	size_t getHours() const {
		return hours;
	}

	size_t getMinutes() const {
		return minutes;
	}

	size_t getSeconds() const {
		return seconds;
	}

	void sortArray(Time* array, size_t count) {
		for (int i = 0; i < count - 1;i++) {
			bool swapped = false;
			for (int j = i + 1;j < count;j++) {
				size_t curr = calculateSeconds(array[i].hours,array[i].minutes,array[i].seconds);
				size_t next = calculateSeconds(array[j].hours, array[j].minutes, array[j].seconds);
				if (curr > next) {
					swap(array[i], array[j]);
					swapped = true;
				}
			}
			if (!swapped) {
				break;
			}
		}
		
	}
};
