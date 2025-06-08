#pragma once
#include "Engineer.h"
#include "Manager.h"

class TechManager : public Manager, public Engineer {
public:
	TechManager(const char* name, int id, const char* project, const char* specialization);
	TechManager(const TechManager& other);
	TechManager& operator=(const TechManager& other);
	~TechManager();

	void printInfo() const override;
	void assignTask(const char* task) const;
};

