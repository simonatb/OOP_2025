#pragma once
#include <iostream>>
using namespace std;
#include <cstring>
 
#pragma warning (disable : 4996)
 
namespace {
	constexpr int MAX_GRADE = 100;
	constexpr int MIN_GRADE = 0;
}
 
class GradeReport {
private:
	int* grades = nullptr;
	int count = 0;
	char* name = nullptr;
 
	void copyFrom(const GradeReport& other);
	void free();
 
public:
	GradeReport() = default;
	GradeReport(const GradeReport& other);
	GradeReport& operator=(const GradeReport& other);
	~GradeReport();
 
	int getGradesCount() const;
	const char* getName() const;
	double getAverage() const;
};
