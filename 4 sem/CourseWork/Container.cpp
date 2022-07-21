#include "Container.h"

void ContainerWithMap::insert(int key, TaxReport* value)
{
	map.insert(std::make_pair(key, value));
}



bool ContainerWithMap::search(int key)
{
	if (map.find(key) == map.end())
		return false;
	else
		return true;
}



void ContainerWithMap::remove(int key)
{
	map.erase(key);
}



void ContainerWithMap::clear()
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		delete it->second;
	map.clear();
}



void ContainerWithMap::print(std::string filename)
{
	std::ofstream file(filename);

	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		it->second->printTaxReportToFile(file);

	file.close();
}



int ContainerWithMap::maxKey()
{
	int max = 0;

	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if (it->first > max)
			max = it->first;

	return max;
}



void ContainerWithMap::searchSurname(std::string surname, std::ofstream& file)
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if (!it->second->surname.compare(surname))
			it->second->printTaxReportToFile(file);
}



void ContainerWithMap::searchName(std::string name, std::ofstream& file)
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if (!it->second->name.compare(name))
			it->second->printTaxReportToFile(file);
}



void ContainerWithMap::searchPatronymic(std::string patronymic, std::ofstream& file)
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if (!it->second->patronymic.compare(patronymic))
			it->second->printTaxReportToFile(file);
}



void ContainerWithMap::searchCity(std::string city, std::ofstream& file)
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if (!it->second->city.compare(city))
			it->second->printTaxReportToFile(file);
}



void ContainerWithMap::searchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file)
{
	for (std::map<int, TaxReport*>::iterator it = map.begin(); it != map.end(); it++)
		if ((it->second->DateOfBirth[0] == dateOfBirth[0]) && (it->second->DateOfBirth[1] == dateOfBirth[1]) && (it->second->DateOfBirth[2] == dateOfBirth[2]))
			it->second->printTaxReportToFile(file);
}





void ContainerWithSplayTree::insert(int key, TaxReport* value)
{
	tree.insert(key, value);
}



bool ContainerWithSplayTree::search(int key)
{
	if (tree.search(key) == nullptr)
		return false;
	else
		return true;
}



void ContainerWithSplayTree::remove(int key)
{
	tree.remove(key);
}



void ContainerWithSplayTree::clear()
{
	tree.clear();
}



void ContainerWithSplayTree::print(std::string filename)
{
	tree.startPrintInOrderTraversalToFile(filename);
}



int ContainerWithSplayTree::maxKey()
{
	return tree.maxKey();
}



void ContainerWithSplayTree::searchSurname(std::string surname, std::ofstream& file)
{
	tree.startSearchSurname(surname, file);
}



void ContainerWithSplayTree::searchName(std::string name, std::ofstream& file)
{
	tree.startSearchName(name, file);
}



void ContainerWithSplayTree::searchPatronymic(std::string patronymic, std::ofstream& file)
{
	tree.startSearchPatronymic(patronymic, file);
}



void ContainerWithSplayTree::searchCity(std::string city, std::ofstream& file)
{
	tree.startSearchCity(city, file);
}

void ContainerWithSplayTree::searchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file)
{
	tree.startSearchDateOfBirth(dateOfBirth, file);
}