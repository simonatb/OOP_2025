#include "ArrClass.h"
#include "CsvFile.h"
#include"DatFile.h"

void readFile(const char* filename, int* data, size_t& length, const fileType& type) {
	switch (type) {
	case fileType::arr:
		ArrFile a;
		a.deserialize(data, length, filename);
		break;
	case fileType::csv:
		CsvFile a;
		a.deserialize(data, length, filename);
		break;

	case fileType::dat:
		DatFile a;
		a.deserialize(data, length, filename);
		break;
	}
}

void writeFile(const char* filename, int* data, size_t& length, const fileType& type) {
	switch (type) {
	case fileType::arr:
		ArrFile a;
		a.serialize(data, length, filename);
		break;
	case fileType::csv:
		CsvFile a;
		a.serialize(data, length, filename);
		break;

	case fileType::dat:
		DatFile a;
		a.serialize(data, length, filename);
		break;
	}
}

void readWriteArray(const char* f1, const char* f2) {
	fileType t1 = helpers::getFileType(f1);
	fileType t2 = helpers::getFileType(f2);
	int* data;
	size_t length;
	readFile(f1, data, length, t1);
	writeFile(f1, data, length, t1);
}

int main() {

}