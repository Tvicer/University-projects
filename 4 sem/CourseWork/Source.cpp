#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>

#include "SplayTree.h"
#include "Container.h"
#include "Factory.h"
#include "Handler.h"

/*void print_node(int key, int depth)
{
	std::cout << "Node " << key << "; depth - " << depth << std::endl;
}

void print_all_order(SplayTree& tree)
{
	std::cout << std::endl << "Preorder:" << std::endl;
	tree.start_pre_order_traversal(print_node);

	std::cout << std::endl << "Inorder:" << std::endl;
	tree.start_in_order_traversal(print_node);

	std::cout << std::endl << "Postorder:" << std::endl;
	tree.start_post_order_traversal(print_node);
}*/

void menuing(Container* container, Handler* handler)
{
	std::cout << "Выберите действие:\n"
		"1) Вывести статистику по базе данных\n"
		"2) Добавить запись в базу данных\n"
		"3) Удалить запись из базы данных(по id)\n"
		"4) Поиск по критерию\n"
		"5) Назад" << std::endl;

	int choise = 0;
	std::cin >> choise;

	if (choise == 1)
	{
		handler->statistics();
	}
	else if (choise == 2)
	{
		handler->addReport(container);
	}
	else if (choise == 3)
	{
		std::cout << "Введите id отчёта" << std::endl;
		std::cin >> choise;

		handler->deleteReport(container, choise);
	}
	else if (choise == 4)
	{
		std::cout << "Выберите критерии поиска:\n1) По фамилии\n2) По имени\n3) По отчеству\n4) По городу\n5) По дате рождения" << std::endl;
		std::cin >> choise;

		if (choise == 1)
		{
			handler->searchSurname(container);
		}
		else if (choise == 2)
		{
			handler->searchName(container);
		}
		else if (choise == 3)
		{
			handler->searchPatronymic(container);
		}
		else if (choise == 4)
		{
			handler->searchCity(container);
		}
		else if (choise == 5)
		{
			handler->searchDateOfBirth(container);
		}

		std::cout << "Результат в файле search.txt" << std::endl;

	}
	else if (choise == 5)
		return;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	std::cout << "Курсовой проект по обработке налоговой отчетности. Выполнен студентом группы М8О-211Б-20 Носовым Александром\n" << std::endl;

	while (true)
	{
		int choise = 0;

		std::cout << "Выберите необходимый пункт меню:\n"
			"1) Инициализировать базу данных и использовать Splay-дерево\n"
			"2) Инициализировать базу данных и использовать std::map\n"
			"3) Использовать Splay-дерево\n"
			"4) Использовать std::map\n"
			"5) Выход" << std::endl;

		std::cin >> choise;

		if (choise == 1)
		{
			Factory* factory = new SplayFactory();
			Container* tree = factory->createDataBaseContainer();
			Handler* handler = new Handler();

			menuing(tree, handler);
			continue;

			
		}
		else if (choise == 2)
		{
			Factory* factory = new MapFactory();
			Container* map = factory->createDataBaseContainer();
			Handler* handler = new Handler();

			menuing(map, handler);
			continue;

		}
		else if (choise == 3)
		{
			Container* tree = new ContainerWithSplayTree();
			Handler* handler = new Handler();

			menuing(tree, handler);
			continue;

		}
		else if (choise == 4)
		{
			Container* map = new ContainerWithMap();
			Handler* handler = new Handler();

			menuing(map, handler);
			continue;

		}
		else if (choise == 5)
			return 0;
		else
			continue;

	}
	
	return 0;
}