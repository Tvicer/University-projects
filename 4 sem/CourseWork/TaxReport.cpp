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

	if (DateOfBirth[1] == 2) // �������
	{
		if (DateOfBirth[2] % 4 == 0) // ���������� ���
			DateOfBirth.insert(iter, rand() % 28 + 1);
		else
			DateOfBirth.insert(iter, rand() % 27 + 1);
	}
	else
	{
		if (DateOfBirth[1] % 2 == 0) // �������� �����
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

	if (yearOfReport[1] == 2) // �������
	{
		if (yearOfReport[2] % 4 == 0) // ���������� ���
			yearOfReport.insert(iter1, rand() % 28 + 1);
		else
			yearOfReport.insert(iter1, rand() % 27 + 1);
	}
	else
	{
		if (yearOfReport[1] % 2 == 0) // �������� �����
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
	file << "�������: " << surname << std::endl;
	file << "���: " << name << std::endl;
	file << "��������: " << patronymic << std::endl;
	file << "�����: " << city << std::endl;
	file << "���� ��������: " << DateOfBirth[0] << months[DateOfBirth[1]] << DateOfBirth[2] << std::endl;
	file << "���: " << INN << std::endl;
	file << "���: " << KPP << std::endl;
	file << "�������� ������: " << yearOfReport[0] << months[yearOfReport[1]] << yearOfReport[2] << std::endl;
	file << "��������������-�������� �����: " << type << std::endl;
	file << "������� �����: " << yearIncome << std::endl;
	file << "���������� ������� ����: " << amountOfWorkingDays << std::endl;
	file << "����� � ������: " << std::fixed << toPay << std::endl;
	if (status == true)
		file << "��������!\n\n" << std::endl;
	else
		file << "����������!\n\n" << std::endl;

}