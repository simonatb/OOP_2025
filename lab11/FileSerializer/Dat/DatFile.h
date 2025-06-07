#pragma once
#include "File.h"

class DatFile : public File {
public:
	void serialize(const int* data, size_t length, const char* filename) const override;
	void deserialize(int* data, size_t& length, const char* filename) override;
};

