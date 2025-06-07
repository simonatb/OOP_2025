#include "DatFile.h"

void DatFile::serialize(const int* data, size_t length, const char* filename) const {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		throw std::logic_error("cannot open file");
	}
	for (size_t i = 0; i < length; i++) {
		ofs << data[i] << " ";
	}
	ofs << std::endl;
	ofs.close();
}

void DatFile::deserialize(int* data, size_t& length, const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		throw std::logic_error("cannot open file");
	}

	int num;
	length = 0;
	int* temp = new int[constants::BUFFER];
	while (ifs >> num) {
		temp[length++] = num;
	}
	ifs.close();

	data = temp;
	temp = nullptr;
}