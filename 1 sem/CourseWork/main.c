#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Header.h"

#include <time.h>
#include <locale.h>
#include <unistd.h>

void print_info()
{
	printf("Автор: Носов Александр Сергеевич М8О-111Б-20\n");
	printf("Принимающий преподаватель: Мокряков Алексей Викторович\nМосковский Авиационный Институт (МАИ)\nKафедра 813 - Компьютерная математика\n");
}



void print_help()
{
	printf("-h вывод информации об аргументах коммандной строки\n");
	printf("-d в лог файл записывается весь диалог с пользователем\n");
	printf("-i вывод информации об авторе, принимающем преподавателе, кафедре и вузе\n");
	printf("-m запуск в форме интерактивного меню(аналогичен запуску без аргументов)\n");
	printf("-s тихая работа приложения - лог файлы не создаются\n");
}







int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	int r = 2, c = 2, g = 0; // row col game
	int** lfield, **rfield;
	FILE* log_f;
	int flag_s = 1, flag_d = 0;
	char fl_log_name[] = "/home/tvicer/kurs/log/log.txt";
	time_t tm = time(NULL);
	log_f = fopen(fl_log_name, "w");
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], "-s"))
			{
				flag_s = 0;
			}
			else
			{
				if (flag_s)
				{
					if (!log_f)
					{
						if (!log_f)
						{
							flag_s = 0;
							flag_d = 0;
						}
					}
				}
				else
					flag_d = 0;
			}

			if (!strcmp(argv[i], "-i"))
			{
				print_info();
				return 0;
			}

			else if (!strcmp(argv[i], "-h"))
			{
				print_help();
				return 0;
			}

			else if (!strcmp(argv[i], "-d"))
			{
				flag_d = 1;
			}
		}




		if (argc == 1)
		{
			if (flag_s)
			{
				if (!log_f)
				{
					if (!log_f)
					{
						flag_s = 0;
						flag_d = 0;
					}
				}
			}
			else
				flag_d = 0;
		}



	}

	g = menu(log_f, flag_d);

	printf("How much rows do you want?: ");
	scanf("%d", &r);
	printf("How much collons do you want?: ");
	scanf("%d", &c);

	if (flag_d)
	{
		fprintf(log_f, "How much rows do you want?: \n");
		fprintf(log_f, "%d\n", r);
		fprintf(log_f, "How much collons do you want?: \n");
		fprintf(log_f, "%d\n", c);
	}



	lfield = (int**)calloc(r, sizeof(int*));
	for (int k = 0; k < r; k++)
		lfield[k] = (int*)calloc(c, sizeof(int));

	rfield = (int**)calloc(r, sizeof(int*));
	for (int k = 0; k < r; k++)
		rfield[k] = (int*)calloc(c, sizeof(int));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			lfield[i][j] = 1;
			rfield[i][j] = 1;
		}


	if (g == 1)
		pvp(lfield, rfield, r, c, log_f, flag_d);
	else if (g == 2)
	{
		//для pve
	}
	else
		printf("Error!\n");


	if (flag_s)
	{
		fprintf(log_f, "\nDate:%s\n", ctime(&tm));
		fprintf(log_f, "work_time:%ld\n", clock() / 1000);
		fprintf(log_f, "completion_code:0\n");
		fprintf(log_f, "user_id:%d\n", getuid());
		fprintf(log_f, "in_file:");
		fprintf(log_f, "\nout_file:");
		fprintf(log_f, "\n");
		fclose(log_f);
	}

	return 0;
}