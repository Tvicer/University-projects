#pragma once
#include "Container.h"

class Factory
{
public:
	virtual Container* createDataBaseContainer() = 0;
	void deleteDataBase() {}
protected:
	void createDataBase()
	{
		static int id = 0;
		std::string fileName;
		for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
		{
			fileName = "DataBase¹" + std::to_string(i) + ".txt";
			std::ofstream outputfile(fileName);

			if (!outputfile.is_open())
			{
				throw std::exception("Generator: Opening file error!\n");
			}

			for (int j = 0; j < 1000; j++)
			{
				TaxReport* report = new TaxReport(id);
				report->printTaxReportToFile(outputfile);
				id++;
				delete report;
			}

			std::cout << "DataBase " << i << " created" << std::endl;
			outputfile.close();
		}
		std::cout << "\n" << std::endl;
	}
};



class SplayFactory : public Factory
{
	Container* createDataBaseContainer() override
	{
		this->createDataBase();
		return new ContainerWithSplayTree;
	}
};



class MapFactory : public Factory
{
	Container* createDataBaseContainer() override
	{
		this->createDataBase();
		return new ContainerWithMap;
	}
};

