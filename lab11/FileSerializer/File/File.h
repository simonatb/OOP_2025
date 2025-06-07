#pragma once
#include <iostream>
#include <fstream>
using namespace std;

enum class fileType {
	dat,
	csv,
	arr
};

namespace constants {
	constexpr size_t BUFFER = 256;
}

namespace helpers {
	fileType getFileType(const char* filename) {
		size_t stringLength = strlen(filename);
		switch (filename[stringLength - 1]) {
		case 't':return fileType::dat;
			break;
		case 'v':return fileType::csv;
			break;
		case 'r':return fileType::arr;
			break;
		default: throw std::logic_error("not a valid file format");
		}
	}

	size_t getFileSize(const char* filename) {
		std::ifstream ifs(filename);
		if (!ifs.is_open()) {
			throw std::logic_error("cannot open file");
		}

		size_t curr = ifs.tellg();
		ifs.seekg(0,std::ios::end);
		size_t size = ifs.tellg();
		ifs.seekg(curr);

		ifs.close();

		return size;
	}
}

class File {
public:
	virtual void serialize(const int* data, size_t length, const char* filename) const;
	virtual void deserialize(int* data, size_t& length, const char* filename);
};

