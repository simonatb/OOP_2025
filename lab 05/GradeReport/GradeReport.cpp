#include "GradeReport.h"
#include <cstring>
 
#pragma warning (disable : 4996)
 
void GradeReport::copyFrom(const GradeReport& other) {
	count = other.count;
	grades = new int[count];
	for (int i = 0; i < count; i++) {
		grades = other.grades;
	}
 
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
} 
 
void GradeReport::free() {
	delete[] name;
	delete[] grades;
	name = nullptr;
	grades = nullptr;
	count = 0;
}
 
GradeReport::GradeReport() {}
 
GradeReport::GradeReport(const GradeReport& other) {
	copyFrom(other);
}
 
GradeReport& GradeReport::operator=(const GradeReport& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
} 
 
GradeReport::~GradeReport() {
	free();
}
 
int GradeReport::getGradesCount() const {
	return count;
}
 
const char* GradeReport::getName() const {
	return name;
}
 
double GradeReport::getAverage() const {
	double sum = 0.0;
	for (int i = 0; i < count; i++) {
		sum += grades[i];
	}
	return sum / count;
}
