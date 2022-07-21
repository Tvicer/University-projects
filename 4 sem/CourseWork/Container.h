#pragma once
#include <map>
#include "SplayTree.h"
#include "TaxReport.h"

#define AMOUNT_OF_DATALISTS 10



class Container
{
public:
	virtual void insert(int key, TaxReport* value) = 0;
	virtual bool search(int key) = 0;
	virtual void remove(int key) = 0;
	virtual void clear() = 0;
	virtual int maxKey() = 0;
	virtual void searchSurname(std::string surname, std::ofstream& file) = 0;
	virtual void searchName(std::string name, std::ofstream& file) = 0;
	virtual void searchPatronymic(std::string patronymic, std::ofstream& file) = 0;
	virtual void searchCity(std::string city, std::ofstream& file) = 0;
	virtual void searchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file) = 0;
	virtual void print(std::string filename) = 0;
};



class ContainerWithMap : public Container
{
public:
	virtual void insert(int key, TaxReport* value) override;
	virtual bool search(int key) override;
	virtual void remove(int key) override;
	virtual void clear() override;
	virtual int maxKey() override;
	virtual void searchSurname(std::string surname, std::ofstream& file) override;
	virtual void searchName(std::string name, std::ofstream& file) override;
	virtual void searchPatronymic(std::string patronymic, std::ofstream& file) override;
	virtual void searchCity(std::string city, std::ofstream& file) override;
	virtual void searchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file) override;
	virtual void print(std::string filename) override;

private:
	std::map<int, TaxReport*> map;
};



class ContainerWithSplayTree : public Container
{
public:
	virtual void insert(int key, TaxReport* value) override;
	virtual bool search(int key) override;
	virtual void remove(int key) override;
	virtual void clear() override;
	virtual int maxKey() override;
	virtual void searchSurname(std::string surname, std::ofstream& file) override;
	virtual void searchName(std::string name, std::ofstream& file) override;
	virtual void searchPatronymic(std::string patronymic, std::ofstream& file) override;
	virtual void searchCity(std::string city, std::ofstream& file) override;
	virtual void searchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file) override;
	virtual void print(std::string filename) override;

private:
	SplayTree tree;
};