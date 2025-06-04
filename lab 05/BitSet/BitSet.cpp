#include "BitSet.h"

namespace helpers {
	unsigned char getMask(unsigned int n) {
		unsigned char mask = 1;
		unsigned int shiftIndex = n % constants::BYTE;
		mask <<= (constants::BYTE - 1 - shiftIndex);
		return mask;
	}

	unsigned int getBucketsIndex(unsigned int n) {
		return n / constants::BYTE;
	}
}

void BitSet::copyFrom(const BitSet& other) {
	maxNum = other.maxNum;
	bucketsCount = other.bucketsCount;
	data = new unsigned char[bucketsCount];
	for (size_t i = 0;i < bucketsCount;i++) {
		data[i] = other.data[i];
	}
}

void BitSet::moveFrom(BitSet&& other) noexcept {
	maxNum = other.maxNum;
	bucketsCount = other.bucketsCount;
	maxNum = bucketsCount = 0;
	data = other.data;
	other.data = nullptr;
}

void BitSet::free() {
	delete[] data;
	data = nullptr;
	maxNum = bucketsCount = 0;
}

BitSet::BitSet(unsigned int max) {
	maxNum = max;
	bucketsCount = max / constants::BYTE + 1;
	data = new unsigned char[bucketsCount];
}

BitSet::BitSet(const BitSet& other) {
	copyFrom(other);
}

BitSet::BitSet(BitSet&& other) noexcept {
	moveFrom(std::move(other));
}

BitSet& BitSet::operator=(BitSet&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

BitSet& BitSet::operator=(const BitSet& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

BitSet::~BitSet() {
	free();
}

void BitSet::addNumber(unsigned int number) {
	if (number > maxNum) {
		return;
	}
	unsigned char mask = helpers::getMask(number);
	unsigned int bucket = helpers::getBucketsIndex(number);
	data[bucket] |= mask;
}

void BitSet::removeNumber(unsigned int number) {
	if (number > maxNum) {
		return;
	}
	unsigned char mask = helpers::getMask(number);
	unsigned int bucket = helpers::getBucketsIndex(number);
	data[bucket] &= ~mask;
}

bool BitSet::isNumber(unsigned int number) const {
	if (number > maxNum) {
		return false;
	}
	unsigned char mask = helpers::getMask(number);
	unsigned int bucket = helpers::getBucketsIndex(number);
	return (data[bucket] & mask);
}

void BitSet::printNumbers() const {
	for (size_t i = 0;i <= maxNum;i++) {
		if (isNumber(i)) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

BitSet unionBitSet(const BitSet& lhs, const BitSet& rhs) {
	BitSet result(std::max(lhs.maxNum, rhs.maxNum));
	unsigned int commonBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (size_t i = 0; i < commonBuckets;i++) {
		result.data[i] = lhs.data[i] | rhs.data[i];
	}

	const BitSet& larger = lhs.maxNum > rhs.maxNum ? lhs : rhs;
	unsigned int largerBuckets = larger.bucketsCount;
	for (size_t i = commonBuckets; i < largerBuckets;i++) {
		result.data[i] = larger.data[i];
	}
	return result;
}

BitSet intersectionBitSet(const BitSet& lhs, const BitSet& rhs) {
	BitSet result(std::max(lhs.maxNum, rhs.maxNum));
	unsigned int commonBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (size_t i = 0; i < commonBuckets;i++) {
		result.data[i] = lhs.data[i] & rhs.data[i];
	}
	return result;
}
