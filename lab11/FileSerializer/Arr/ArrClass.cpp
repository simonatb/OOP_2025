#include "ArrClass.h"

void ArrFile::serialize(const int* data, size_t length, const char* filename) const {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		throw std::logic_error("cannot open file");
	}
	ofs << "[ ";
	for (size_t i = 0; i < length; i++) {
			ofs << data[i] << "";
	}
	ofs << "]" << std::endl;
	ofs.close();
}

void ArrFile::deserialize(int* data, size_t& length, const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		throw std::logic_error("cannot open file");
	}
	int num;
	length = 0;
	int* temp = new int[constants::BUFFER];
	char comma;

	ifs >> comma;
	if (comma != '[') {
		throw std::logic_error("not correct file format");
	}

	while (true) {
		if (!(ifs >> num)) break;
		temp[length++] = num;

		ifs >> comma;
		if (comma == ']') break;
	}
	ifs.close();

	data = temp;
	temp = nullptr;
}