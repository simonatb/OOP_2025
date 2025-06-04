#pragma once
#include <iostream>
using namespace std;

namespace constants {
	constexpr size_t BYTE = 8;
}

namespace helpers {
	unsigned char getMask(unsigned int n);
	unsigned int getBucketsIndex(unsigned int n);
}

class BitSet {
private:
	unsigned char* data;
	unsigned int maxNum;
	unsigned int bucketsCount;

	void copyFrom(const BitSet& other);
	void moveFrom(BitSet&& other) noexcept;
	void free();

public:
	BitSet(unsigned int max);
	BitSet(const BitSet& other);
	BitSet(BitSet&& other) noexcept;
	BitSet& operator=(BitSet&& other) noexcept;
	BitSet& operator=(const BitSet& other);
	~BitSet();

	void addNumber(unsigned int number);
	void removeNumber(unsigned int number);
	void printNumbers() const;
	bool isNumber(unsigned int number) const;

	friend BitSet unionBitSet(const BitSet& lhs, const BitSet& rhs);
	friend BitSet intersectionBitSet(const BitSet& lhs, const BitSet& rhs);
};
