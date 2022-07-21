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
	std::cout << "�������� ��������:\n"
		"1) ������� ���������� �� ���� ������\n"
		"2) �������� ������ � ���� ������\n"
		"3) ������� ������ �� ���� ������(�� id)\n"
		"4) ����� �� ��������\n"
		"5) �����" << std::endl;

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
		std::cout << "������� id ������" << std::endl;
		std::cin >> choise;

		handler->deleteReport(container, choise);
	}
	else if (choise == 4)
	{
		std::cout << "�������� �������� ������:\n1) �� �������\n2) �� �����\n3) �� ��������\n4) �� ������\n5) �� ���� ��������" << std::endl;
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

		std::cout << "��������� � ����� search.txt" << std::endl;

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

	std::cout << "�������� ������ �� ��������� ��������� ����������. �������� ��������� ������ �8�-211�-20 ������� �����������\n" << std::endl;

	while (true)
	{
		int choise = 0;

		std::cout << "�������� ����������� ����� ����:\n"
			"1) ���������������� ���� ������ � ������������ Splay-������\n"
			"2) ���������������� ���� ������ � ������������ std::map\n"
			"3) ������������ Splay-������\n"
			"4) ������������ std::map\n"
			"5) �����" << std::endl;

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