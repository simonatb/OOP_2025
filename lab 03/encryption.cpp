#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(std::ifstream& ifs) {
	int num;
	while (ifs.read((char*)&num, sizeof(int))) {
		cout << (num + 2) << " ";
	}
	cout << endl;
	ifs.close();
}

void readFromFile(const char* filename) {
	std::ifstream ifs(filename, std::ios::binary);
	if (!ifs.is_open()) {
		throw std::logic_error("file not open");
	}
	readFromFile(ifs);
}

int main() {
	std::ofstream ofs("binary.txt", std::ios::binary);
	if (!ofs.is_open()) {
		throw std::logic_error("file not open");
	}
	int arr[] = { 23,48,3,12,4006 };
	ofs.write((const char*)arr, 5 * sizeof(int));
	ofs.close();
	readFromFile("binary.txt");
}
