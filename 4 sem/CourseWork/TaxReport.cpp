#include "TaxReport.h"

TaxReport::TaxReport()
{

}


TaxReport::TaxReport(const long int& id)
{
	this->id = id;

	surname = surnames[rand() % surnames.size()];
	name = names[rand() % names.size()];
	patronymic = patronymics[rand() % patronymics.size()];

	city = cities[rand() % cities.size()];

	DateOfBirth.push_back(rand() % 12);
	DateOfBirth.push_back(rand() % 104 + 1900);

	auto iter = DateOfBirth.cbegin();

	if (DateOfBirth[1] == 2) // февраль
	{
		if (DateOfBirth[2] % 4 == 0) // високосный год
			DateOfBirth.insert(iter, rand() % 28 + 1);
		else
			DateOfBirth.insert(iter, rand() % 27 + 1);
	}
	else
	{
		if (DateOfBirth[1] % 2 == 0) // нечётный месяц
			DateOfBirth.insert(iter, rand() % 29 + 1);
		else
			DateOfBirth.insert(iter, rand() % 30 + 1);
	}

	INN = ((long long int)rand() * (long long int)rand() * (long long int)rand() * (long long int)rand()) % 999999999999;
	KPP = ((int)rand() * (int)rand()) % 999999999;

	yearOfReport.push_back(rand() % 12);

	int year = 2025;
	while (year > 2022)
		year = rand() % 104 + 18 + DateOfBirth[2];
	yearOfReport.push_back(year);

	auto iter1 = yearOfReport.cbegin();

	if (yearOfReport[1] == 2) // февраль
	{
		if (yearOfReport[2] % 4 == 0) // високосный год
			yearOfReport.insert(iter1, rand() % 28 + 1);
		else
			yearOfReport.insert(iter1, rand() % 27 + 1);
	}
	else
	{
		if (yearOfReport[1] % 2 == 0) // нечётный месяц
			yearOfReport.insert(iter1, rand() % 29 + 1);
		else
			yearOfReport.insert(iter1, rand() % 30 + 1);
	}

	type = organisationType[rand() % organisationType.size()];

	yearIncome = MROT * 12 + ((int)rand() * (int)rand()) % 99999999;

	amountOfWorkingDays = rand() % 14 + 233;

	toPay = double(yearIncome) / 100 * NDFL;

	if (rand() % 2 == 0)
		status = true;
	else
		status = false;
}



void TaxReport::printTaxReportToFile(std::ofstream& file)
{
	file << "Id: " << id << std::endl;
	file << "Фамилия: " << surname << std::endl;
	file << "Имя: " << name << std::endl;
	file << "Отчество: " << patronymic << std::endl;
	file << "Город: " << city << std::endl;
	file << "Дата рождения: " << DateOfBirth[0] << months[DateOfBirth[1]] << DateOfBirth[2] << std::endl;
	file << "ИНН: " << INN << std::endl;
	file << "КПП: " << KPP << std::endl;
	file << "Отчётный период: " << yearOfReport[0] << months[yearOfReport[1]] << yearOfReport[2] << std::endl;
	file << "Оргазизационно-правовая форма: " << type << std::endl;
	file << "Годовой доход: " << yearIncome << std::endl;
	file << "Количество рабочих дней: " << amountOfWorkingDays << std::endl;
	file << "Итого к оплате: " << std::fixed << toPay << std::endl;
	if (status == true)
		file << "Оплачено!\n\n" << std::endl;
	else
		file << "Неоплачено!\n\n" << std::endl;

}