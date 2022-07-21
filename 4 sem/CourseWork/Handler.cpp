#include "Handler.h"

void Handler::statistics()
{
	std::string fileName;
	std::string word;

	std::map<std::string, int> countSurname;
	std::map<std::string, int> countName;
	std::map<std::string, int> countPatronymic;

	std::map<std::string, int> countCity;

	std::map<int, int> countBirthDay;
	std::map<std::string, int> countBirthMonth;
	std::map<int, int> countBirthYear;

	std::map<int, int> countReportDay;
	std::map<std::string, int> countReportMonth;
	std::map<int, int> countReportYear;

	std::map<std::string, int> countType;

	long long int countyearIncome = 0;
	int countWorkingDays = 0;

	long double countToPay = 0.0;

	std::map<bool, int> countStatus;

	int amountOfReports = 0;

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream file(fileName);

		if (!file.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		file >> word;
		file >> word;

		while (!file.eof())
		{
			amountOfReports++;


			file >> word;
			file >> word;
			if (countSurname.find(word) == countSurname.end())
				countSurname.insert(std::make_pair(word, 1));
			else
				countSurname[word]++;

			file >> word;
			file >> word;
			if (countName.find(word) == countName.end())
				countName.insert(std::make_pair(word, 1));
			else
				countName[word]++;

			file >> word;
			file >> word;
			if (countPatronymic.find(word) == countPatronymic.end())
				countPatronymic.insert(std::make_pair(word, 1));
			else
				countPatronymic[word]++;

			file >> word;
			file >> word;
			if (countCity.find(word) == countCity.end())
				countCity.insert(std::make_pair(word, 1));
			else
				countCity[word]++;

			file >> word;
			file >> word;
			file >> word;
			if (countBirthDay.find(std::stoi(word)) == countBirthDay.end())
				countBirthDay.insert(std::make_pair(std::stoi(word), 1));
			else
				countBirthDay[std::stoi(word)]++;

			file >> word;
			word = " " + word + " ";
			if (countBirthMonth.find(word) == countBirthMonth.end())
				countBirthMonth.insert(std::make_pair(word, 1));
			else
				countBirthMonth[word]++;

			file >> word;
			if (countBirthYear.find(std::stoi(word)) == countBirthYear.end())
				countBirthYear.insert(std::make_pair(std::stoi(word), 1));
			else
				countBirthYear[std::stoi(word)]++;

			file >> word;
			file >> word;


			file >> word;
			file >> word;

			file >> word;
			file >> word;
			file >> word;
			if (countReportDay.find(std::stoi(word)) == countReportDay.end())
				countReportDay.insert(std::make_pair(std::stoi(word), 1));
			else
				countReportDay[std::stoi(word)]++;

			file >> word;
			word = " " + word + " ";
			if (countReportMonth.find(word) == countReportMonth.end())
				countReportMonth.insert(std::make_pair(word, 1));
			else
				countReportMonth[word]++;

			file >> word;
			if (countReportYear.find(std::stoi(word)) == countReportYear.end())
				countReportYear.insert(std::make_pair(std::stoi(word), 1));
			else
				countReportYear[std::stoi(word)]++;

			file >> word;
			file >> word;
			file >> word;
			if (countType.find(word) == countType.end())
				countType.insert(std::make_pair(word, 1));
			else
				countType[word]++;

			file >> word;
			file >> word;
			file >> word;
			countyearIncome += std::stoi(word);

			file >> word;
			file >> word;
			file >> word;
			file >> word;
			countWorkingDays += std::stoi(word);

			file >> word;
			file >> word;
			file >> word;
			file >> word;
			countToPay += std::stod(word);

			file >> word;
			if (word == "Оплачено!")
			{
				if (countStatus.find(true) == countStatus.end())
					countStatus.insert(std::make_pair(true, 1));
				else
					countStatus[true]++;
			}
			else
			{
				if (countStatus.find(false) == countStatus.end())
					countStatus.insert(std::make_pair(false, 1));
				else
					countStatus[false]++;
			}

			file >> word;
			file >> word;
		}

		file.close();
	}

	countyearIncome /= amountOfReports; // среднее значение по всей базе данных
	countWorkingDays /= amountOfReports; // среднее значение по всей базе данных
	countToPay /= amountOfReports; // среднее значение по всей базе данных

	fileName = "statistics.txt";
	std::ofstream outputfile(fileName);

	for (std::map<std::string, int>::iterator it = countSurname.begin(); it != countSurname.end(); it++)
	{
		//std::cout << "Фамилия " << it->first << " встретилась " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
		outputfile << "Фамилия " << it->first << " встретилась " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<std::string, int>::iterator it = countName.begin(); it != countName.end(); it++)
	{
		//std::cout << "Имя " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
		outputfile << "Имя " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<std::string, int>::iterator it = countPatronymic.begin(); it != countPatronymic.end(); it++)
	{
		//std::cout << "Отчество " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
		outputfile << "Отчество " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<std::string, int>::iterator it = countCity.begin(); it != countCity.end(); it++)
	{
		//std::cout << "Город " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
		outputfile << "Город " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<int, int>::iterator it = countBirthDay.begin(); it != countBirthDay.end(); it++)
	{
		outputfile << "Число рождения " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<std::string, int>::iterator it = countBirthMonth.begin(); it != countBirthMonth.end(); it++)
	{
		outputfile << "Месяц рождения " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<int, int>::iterator it = countBirthYear.begin(); it != countBirthYear.end(); it++)
	{
		outputfile << "Год рождения " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<int, int>::iterator it = countReportDay.begin(); it != countReportDay.end(); it++)
	{
		outputfile << "Число подачи отчёта " << it->first << " встретилось " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<std::string, int>::iterator it = countReportMonth.begin(); it != countReportMonth.end(); it++)
	{
		outputfile << "Месяц подачи отчёта " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	for (std::map<int, int>::iterator it = countReportYear.begin(); it != countReportYear.end(); it++)
	{
		outputfile << "Год подачи отчёта " << it->first << " встретился " << it->second << " раз ( " << double(it->second) / amountOfReports * 100 << "% )" << std::endl;
	}

	outputfile << "\n";

	outputfile << "Среднегодовой доход: " << countyearIncome << " рублей" << std::endl;
	outputfile << "\n";

	outputfile << "Среднее количество рабочих дней: " << countWorkingDays << std::endl;
	outputfile << "\n";

	outputfile << std::fixed << "Средний платёж по налогам: " << countToPay << " рублей" << std::endl;
	outputfile << "\n";

	outputfile.close();
}

void Handler::initTree(Container* container, std::ifstream& file)
{
	std::string word;

	file >> word;
	file >> word;

	while (!file.eof())
	{
		TaxReport* report = new TaxReport();

		report->id = std::stoi(word);

		file >> word;
		file >> word;
		report->surname = word;


		file >> word;
		file >> word;
		report->name = word;


		file >> word;
		file >> word;
		report->patronymic = word;


		file >> word;
		file >> word;
		report->city = word;


		file >> word;
		file >> word;
		file >> word;
		report->DateOfBirth.push_back(std::stoi(word));


		file >> word;
		word = " " + word + " ";
		for (int i = 0; i < 12; i++)
			if (!months[i].compare(word))
				report->DateOfBirth.push_back(i);


		file >> word;
		report->DateOfBirth.push_back(std::stoi(word));


		file >> word;
		file >> word;
		report->INN = std::stoll(word);


		file >> word;
		file >> word;
		report->KPP = std::stoi(word);

		file >> word;
		file >> word;
		file >> word;
		report->yearOfReport.push_back(std::stoi(word));


		file >> word;
		word = " " + word + " ";
		for (int i = 0; i < 12; i++)
			if (!months[i].compare(word))
				report->yearOfReport.push_back(i);


		file >> word;
		report->yearOfReport.push_back(std::stoi(word));


		file >> word;
		file >> word;
		file >> word;
		report->type = word;


		file >> word;
		file >> word;
		file >> word;
		report->yearIncome = std::stoi(word);


		file >> word;
		file >> word;
		file >> word;
		file >> word;
		report->amountOfWorkingDays = std::stoi(word);


		file >> word;
		file >> word;
		file >> word;
		file >> word;
		report->toPay = std::stod(word);


		file >> word;
		if (word == "Оплачено!")
		{
			report->status = true;
		}
		else
		{
			report->status = false;
		}

		container->insert(report->id, report);

		file >> word;
		file >> word;
	}
}



void Handler::deleteReport(Container* container, int id)
{
	std::string fileName;

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream file(fileName);

		if (!file.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, file);

		if (container->search(id))
		{
			container->remove(id);

			container->print(fileName);

			container->clear();

			file.close();

			return;
		}
		else
			container->clear();

		file.close();

	}
}



void Handler::addReport(Container* container)
{
	std::string fileName = "DataBase№" + std::to_string(AMOUNT_OF_DATALISTS - 1) + ".txt";
	std::ifstream file(fileName);
	TaxReport* report = new TaxReport();

	int day = 0, status = 0;
	std::string month;
	int year = 0;

	if (!file.is_open())
	{
		throw std::exception("Handler: Opening file error!\n");
	}

	initTree(container, file);

	report->id = container->maxKey() + 1;

	std::cout << "Введите ФИО. Пример: Иванов Иван Иванович " << std::endl;
	std::cin >> report->surname >> report->name >> report->patronymic;

	std::cout << "Введите город проживания. Пример: Москва " << std::endl;
	std::cin >> report->city;

	std::cout << "Введите дату рождения. Пример: 01 января 2022 " << std::endl;
	std::cin >> day >> month >> year;

	report->DateOfBirth.push_back(day);

	month = " " + month + " ";
	for (int i = 0; i < 12; i++)
		if (!months[i].compare(month))
			report->DateOfBirth.push_back(i);

	report->DateOfBirth.push_back(year);

	std::cout << "Введите ИНН(максимум 12 знаков): " << std::endl;
	std::cin >> report->INN;

	std::cout << "Введите КПП(максимум 9 знаков): " << std::endl;
	std::cin >> report->KPP;

	std::cout << "Введите дату подачи отчёта. Пример: 01 января 2022 " << std::endl;
	std::cin >> day >> month >> year;

	report->yearOfReport.push_back(day);

	month = " " + month + " ";
	for (int i = 0; i < 12; i++)
		if (!months[i].compare(month))
			report->yearOfReport.push_back(i);

	report->yearOfReport.push_back(year);

	std::cout << "Введите оргазизационно-правовую форму. Пример: ОАО " << std::endl;
	std::cin >> report->type;

	std::cout << "Введите годовый доход: " << std::endl;
	std::cin >> report->yearIncome;

	std::cout << "Введите количество рабочих дней: " << std::endl;
	std::cin >> report->amountOfWorkingDays;

	report->toPay = double(report->yearIncome) / 100 * NDFL;

	std::cout << "Вы оплатили налог?\n1) Да\n2) Нет " << std::endl;
	std::cin >> status;

	if (status == 1)
		report->status = true;
	else
		report->status = false;

	container->insert(report->id, report);

	container->print(fileName);

	container->clear();
}



void Handler::searchSurname(Container* container)
{
	std::string fileName;
	std::string surname;

	std::cout << "Введите фамилию:" << std::endl;
	std::cin >> surname;

	std::ofstream outputfile("search.txt");

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream inputfile(fileName);

		if (!inputfile.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, inputfile);

		container->searchSurname(surname, outputfile);

		container->clear();

		inputfile.close();

	}

	outputfile.close();
}



void Handler::searchName(Container* container)
{
	std::string fileName;
	std::string name;

	std::cout << "Введите имя:" << std::endl;
	std::cin >> name;

	std::ofstream outputfile("search.txt");

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream inputfile(fileName);

		if (!inputfile.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, inputfile);

		container->searchName(name, outputfile);

		container->clear();

		inputfile.close();

	}

	outputfile.close();
}



void Handler::searchPatronymic(Container* container)
{
	std::string fileName;
	std::string patronymic;

	std::cout << "Введите отчество:" << std::endl;
	std::cin >> patronymic;

	std::ofstream outputfile("search.txt");

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream inputfile(fileName);

		if (!inputfile.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, inputfile);

		container->searchPatronymic(patronymic, outputfile);

		container->clear();

		inputfile.close();

	}

	outputfile.close();
}



void Handler::searchCity(Container* container)
{
	std::string fileName;
	std::string city;

	std::cout << "Введите город:" << std::endl;
	std::cin >> city;

	std::ofstream outputfile("search.txt");

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream inputfile(fileName);

		if (!inputfile.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, inputfile);

		container->searchCity(city, outputfile);

		container->clear();

		inputfile.close();

	}

	outputfile.close();
}



void Handler::searchDateOfBirth(Container* container)
{
	std::string fileName;
	std::vector<int> dateOfBirth;

	int day = 0, year = 0;
	std::string month;

	std::cout << "Введите дату рождения. Пример: 01 Января 2022" << std::endl;
	std::cin >> day >> month >> year;

	dateOfBirth.push_back(day);

	month = " " + month + " ";
	for (int i = 0; i < 12; i++)
		if (!months[i].compare(month))
			dateOfBirth.push_back(i);

	dateOfBirth.push_back(year);

	std::ofstream outputfile("search.txt");

	for (int i = 0; i < AMOUNT_OF_DATALISTS; i++)
	{
		fileName = "DataBase№" + std::to_string(i) + ".txt";
		std::ifstream inputfile(fileName);

		if (!inputfile.is_open())
		{
			throw std::exception("Handler: Opening file error!\n");
		}

		initTree(container, inputfile);

		container->searchDateOfBirth(dateOfBirth, outputfile);

		container->clear();

		inputfile.close();

	}

	outputfile.close();
}