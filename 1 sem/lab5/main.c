#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <io.h>
#include <math.h>


#define ERROR_FILE_OPEN -3

void menu() {
	printf("Лабораторная работа №5 \n");
	printf("Носов Александр М8О-111Б-20 \n");
	printf("Меню: \n");
	printf("Введите 1 чтобы запустить \"Решение СЛАУ методом Гаусса\" \n");
	printf("Введите 2 чтобы запустить \"Построение столбчатой диаграммы\" \n");
	printf("Введите 3 чтобы запустить \"Рассчитать частоту символов в файле\" \n");
	printf("Введите 4 чтобы запустить \"Перенести текст в новый файл\"\n");
	printf("Введите 0 чтобы закрыть программу \n");
}
//-------------------------------------
// Получение матрицы без i-й строки и j-го столбца
void GetMatr(float* k, float* p, int i, int j, int n) {
	int ki, kj, di, dj, ip, ik;
	di = 0;
	for (ki = 0; ki < n; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < n; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			ip = ki * n + kj;
			ik = (ki + di) * (n + 1) + (kj + dj);
			p[ip] = k[ik];
		}
	}
}

// Рекурсивное вычисление определителя
float Determinant(float* mas, int m) {
	int i, j, k, n;
	float d, * p;
	n = m - 1;
	p = (float*)calloc(n * n, sizeof(float));
	if (p == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}

	j = 0; d = 0;
	k = 1; //(-1) в степени i
	if (m < 1) printf("Определитель вычислить невозможно!");
	if (m == 1) {
		d = mas[0];
		printf("ddd = %f\n", d);
		return(d);
	}
	if (m == 2) {
		d = mas[0] * mas[3] - (mas[1] * mas[2]);
		return(d);
	}
	if (m > 2) {
		for (i = 0; i < m; i++) {
			GetMatr(mas, p, i, 0, n);

			d = d + k * mas[i * m] * Determinant(p, n);

			k = -k;
		}
	}
	return(d);
}

//----------------------------------------
void clean_stdin(void) {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
//----------------------------------------

// Функция выделения подстроки
char* substr(char* str, char* s, int start, int length)
{
	// Определить длину исходной строки
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
		len++;
	// Определить позицию последнего символа подстроки
	if (length > 0)
	{
		if (start + length < len)
			len = start + length;
	}
	else // length < 0
		len = len + length;

	// Копирование символов подстроки
	int j = 0;
	for (int i = start; i < len; i++)
	{
		s[j] = str[i]; j++;
	}
	s[j] = '\0';
	return(s);
}

int rabor(FILE* ofile, char* str, int len, int ogr) {
	int pps = 0, i, j, kp = 0, rp, kop, kdp;
	for (i = 0; i < len; i++) {
		if (str[i] == ' ' || str[i] == '\n') {
			kp++;
			if (i > ogr) {
				rp = ogr - pps + 1;
				kop = rp / (kp - 2);
				kdp = rp % (kp - 2);
				break;
			}
			pps = i + 1;
		}
	}
	//---------------------------
	for (i = 0; i < pps - 1; i++) {

		fwrite(&str[i], sizeof(char), 1, ofile);
		if (str[i] == ' ') {
			for (j = 0; j < kop; j++) {

				fwrite(" ", sizeof(char), 1, ofile);
			}
			if (kdp > 0) {

				fwrite(" ", sizeof(char), 1, ofile);
				kdp--;
			}
		}
	}
	return pps;
}
//------------------------------------------------------

int prog1()
{
	int m, i, j;
	printf("Введите кол-во переменных:\n");
	scanf("%d", &m);

	float* k, * a, d;
	k = (float*)calloc(m * m, sizeof(float));
	if (k == NULL)
	{
		printf("Out of memory.\n");
		exit(1);
	}
	a = (float*)calloc(m, sizeof(float));
	if (a == NULL)
	{
		printf("Out of memory.\n");
		exit(1);
	}

	//------- Задаем коэффициенты -----------
	for (i = 0; i < m; i++)
	{                        // цикл по строкам
		printf("Введите коэффициенты %d-го уравнения:\n", i + 1);
		for (j = 0; j < m; j++) 
		{                    // цикл по столбцам
			printf("k[%d][%d] = ", i, j);
			scanf("%f", (k + i * m + j));
		}
	}

	//------- Задаем св. члены -----------
	printf("Введите свободные члены:\n");
	for (i = 0; i < m; i++) {
		printf("a[%d] = ", i);
		scanf("%f", (a + i));
	}



	//========== ПЕЧАТЬ ИСХОДНОЙ МАТРИЦЫ ===============
	printf("---------------------------------------------------------------------------------------\n");
	printf("Исходная матрица\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%f\t", k[i * m + j]);
		}
		printf("%f\t", a[i]);
		printf("\n");
	}
	printf("---------------------------------------------------------------------------------------\n");

	//========== ВЫЧИСЛЯЕМ ОПРЕДЕЛИТЕЛЬ ===============
	d = Determinant(k, m);

	if (d == 0)
	{
		printf("Определитель равен нулю, СЛАУ не имеет решения\n");
		return 0;
	}
	else {
		//========== РЕШЕНИЕ СИСТЕМЫ ПО ГАУСУ ===============
		float temp, koef;
		int ii, jj, num;
		double mkoef;
		//-----------------------------------	
		ii = 0;
		jj = 0;

		while (ii != m)
		{
			//max
			mkoef = fabs(k[ii * m + jj]);
			num = ii;
			for (i = ii + 1; i < m; i++)
			{

				if (fabs(k[i * m + jj]) > mkoef)
				{
					mkoef = fabs(k[i * m + jj]);
					num = i;
				}
			}
			//перестановка
			if (num != ii) 
			{
				for (j = 0; j < m; j++)
				{
					temp = k[num * m + j];
					k[num * m + j] = k[ii * m + j];
					k[ii * m + j] = temp;
				}
				temp = a[num];
				a[num] = a[ii];
				a[ii] = temp;
			}
			//нормализация
			for (i = ii; i < m; i++)
			{
				koef = k[i * m + jj];
				if (koef != 0) {
					a[i] = a[i] / koef;
					for (j = 0; j < m; j++) {
						k[i * m + j] = k[i * m + j] / koef;
					}
				}
			}

			//вычитание
			for (i = ii + 1; i < m; i++)
			{
				a[i] = a[i] - a[ii];
				for (j = 0; j < m; j++)
				{
					k[i * m + j] = k[i * m + j] - k[ii * m + j];
				}
			}
			ii++;
			jj++;
		}

		// обратная подстановка
		printf("Корни уравнения:\n");
		for (i = m - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < m; j++)
			{
				a[i] = a[i] - a[j] * k[i * m + j];
			}
			printf("x%d = %.3f\n", i, a[i]);
		}
	}

	_getch();
	return 0;
}

void prog2() {
	int m, i;
	/*printf("Введите кол-во переменных:\n");
	scanf("%d", &m);*/


	//массив символов и кол-во 
	char* ch;
	/*ch = (char *)calloc(m, sizeof(char));
	if (ch == NULL){
	printf("Out of memory.\n");
	exit(1);
	}*/
	unsigned int* k;
	/*k = (unsigned int *)calloc(m, sizeof(unsigned int));
	if (k == NULL){
	printf("Out of memory.\n");
	exit(1);
	}*/

	//------- заполняем массивы -----------
	char cc;
	int kk;
	/*for (i = 0; i < m; i++){
	printf("символ%d = ", i);
	scanf(" %c", &cc);
	printf("количественная характеристика[%d] = ", i);
	scanf("%d", &kk);
	ch[i] = cc;
	k[i] = kk;
	}*/


	FILE* iofile = NULL;

	/*iofile = fopen("output.bin", "wb");
	if (iofile == NULL) {
	printf("Error opening file");
	_getch();
	exit(ERROR_FILE_OPEN);
	}

	for (i = 0; i < m; i++){
	fwrite(&ch[i], sizeof(char), 1, iofile);
	fwrite(&k[i], sizeof(int), 1, iofile);
	}

	fclose(iofile);
	free(ch);
	free(k);*/



	long size;

	iofile = fopen("output.bin", "r");
	if (iofile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	fseek(iofile, 0L, SEEK_END);
	size = ftell(iofile);

	fseek(iofile, 0L, SEEK_SET);

	m = size / (sizeof(char) + sizeof(int));
	printf("Кол-во %d\n", m);

	ch = (char*)calloc(m, sizeof(char));
	if (ch == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}

	k = (unsigned int*)calloc(m, sizeof(unsigned int));
	if (k == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}

	for (i = 0; i < m; i++) {
		fread(&ch[i], sizeof(char), 1, iofile);
		fread(&k[i], sizeof(int), 1, iofile);
	}

	fclose(iofile);

	for (i = 0; i < m; i++) {
		printf("символ = %c\t", ch[i]);
		printf("количественная характеристика = %d\n", k[i]);
	}

	unsigned int maxk = 0, sumk = 0;
	for (i = 0; i < m; i++) {
		//printf("k = %d\n", k[i]);
		if (k[i] >= maxk) {
			maxk = k[i];
		}
		sumk = sumk + k[i];
	}
	//printf("maxk = %d\n", maxk);

	int kz, j;
	printf("Относительно самого большого значения\n");
	for (j = 0; j < 20; j++) {
		for (i = 0; i < m; i++) {
			kz = k[i] * 20 / maxk;
			if (kz >= 20 - j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < m; i++) {
		printf("%c", ch[i]);
	}
	printf("\n");

	//int kk;
	kk = maxk * 50 / sumk;;
	printf("-----------------------------\n");
	printf("Относительно суммы всех значений\n");
	for (j = 0; j < kk; j++) {
		for (i = 0; i < m; i++) {
			kz = k[i] * 50 / sumk;
			if (kz >= kk - j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < m; i++) {
		printf("%c", ch[i]);
	}
	printf("\n");

	/*for (i = 0; i < m; i++){
	kz = k[i] * 50 / sumk;

	printf("%c", ch[i]);
	for (j = 0; j < kz; j++){
	printf("*");
	}
	printf("\n");
	}*/

	_getch();
}

void prog3() {
	int n = 256, i, a[256];

	for (i = 0; i < n; i++) {
		a[i] = 0;
	}

	FILE* iofile = NULL;

	iofile = fopen("file5_3.txt", "r");
	if (iofile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}


	long size; char m;


	fseek(iofile, 0L, SEEK_END);
	size = ftell(iofile);
	fseek(iofile, 0L, SEEK_SET);

	for (i = 0; i < size; i++) {
		fread(&m, sizeof(char), 1, iofile);
		a[m]++;
	}

	fclose(iofile);

	int maxk = 0, sumk = 0;
	for (i = 0; i < n; i++) {
		if (a[i] >= maxk) {
			maxk = a[i];
		}
		sumk = sumk + a[i];
	}


	int kz, j;
	printf("Относительно самого большого значения\n");
	for (j = 0; j < 20; j++) {
		for (i = 0; i < n; i++) {
			if (a[i] != 0) {
				kz = a[i] * 20 / maxk;
				if (kz >= 20 - j) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		if (a[i] != 0 && i != 10) {
			printf("%c", i);
		}
	}
	printf("\n");

	printf("-----------------------------\n");

	int kk;
	kk = maxk * 50 / sumk;;
	printf("Относительно суммы всех значений\n");
	for (j = 0; j < kk; j++) {
		for (i = 0; i < n; i++) {
			if (a[i] != 0) {
				kz = a[i] * 50 / sumk;
				if (kz >= kk - j) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		if (a[i] != 0 && i != 10) {
			printf("%c", i);
		}
	}
	printf("\n");


	iofile = fopen("fileout5_3.txt", "wt");
	if (iofile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	double pr;
	for (i = 0; i < n; i++) {
		if (a[i] != 0 && i != 10) {
			pr = a[i] * 100.0 / sumk;
			fprintf(iofile, "\"%c\" - %.1f %%\n", i, pr);
		}
	}
	fclose(iofile);
	_getch();
}

void prog4() {
	int n = 400, ogr = 80;
	char* str;
	str = (char*)calloc(n, sizeof(char));
	if (str == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}

	char* s;
	s = (char*)calloc(n, sizeof(char));
	if (s == NULL) {
		printf("Out of memory.\n");
		exit(1);
	}

	FILE* ifile = NULL;
	FILE* ofile = NULL;

	char inFile[256];
	printf("Имя файла для чтения: \n");
	scanf("%s", &inFile);
	printf("\n");

	char outFile[256];
	printf("Имя файла для записи: \n");
	scanf("%s", &outFile);
	printf("\n");

	ifile = fopen(inFile, "r");
	if (ifile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}

	ofile = fopen(outFile, "w");
	if (ofile == NULL) {
		printf("Error opening file");
		_getch();
		exit(ERROR_FILE_OPEN);
	}
	int len, pps;
	while (!feof(ifile)) {
		if (fgets(str, n, ifile)) {
			len = strlen(str);
			if (len <= ogr) {

				fputs(str, ofile);
			}
			else {
				while (len > ogr) {
					pps = rabor(ofile, str, len, ogr);
					str = substr(str, s, pps, len - pps);
					fputs("\n", ofile);
					len = strlen(str);
				}
				fputs(str, ofile);
			}
		}
	}

	fclose(ifile);
	fclose(ofile);
}

int main()
{
	int num;
	setlocale(LC_ALL, "Russian");

	menu();

	scanf("%d", &num);

	while (num != 0)
	{
		while (num == 1)
		{
			printf("Bыполнение 1: \n");
			prog1();
			printf("Выберете программу или нажмите 9, чтобы показать меню: \n");
			scanf("%d", &num);
		}
		while (num == 2)
		{
			printf("Bыполнение 2: \n");
			prog2();
			printf("Выберете программу или нажмите 9, чтобы показать меню: \n");
			scanf("%d", &num);
		}
		while (num == 3)
		{
			printf("Bыполнение 3: \n");
			prog3();
			printf("Выберете программу или нажмите 9, чтобы показать меню: \n");
			scanf("%d", &num);
		}
		while (num == 4)
		{
			printf("Bыполнение 4: \n");
			prog4();
			printf("Выберете программу или нажмите 9, чтобы показать меню: \n");
			scanf("%d", &num);
		}

		if (num == 9)
		{
			menu();
			scanf("%d", &num);
		}

	}

	_getch();
	return 0;
}