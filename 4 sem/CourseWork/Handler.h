#pragma once
#include "TaxReport.h"
#include "Container.h"
#include <cstring>
#include <string>

class Handler
{
public:

	void statistics();

private:
	void initTree(Container* container, std::ifstream& file);

public:
	void deleteReport(Container* container, int id);

	void addReport(Container* container);

	void searchSurname(Container* container);

	void searchName(Container* container);

	void searchPatronymic(Container* container);

	void searchCity(Container* container);

	void searchDateOfBirth(Container* container);
};

