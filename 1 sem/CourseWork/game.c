#include <stdio.h>

int menu(FILE* log_f, int flag_d)
{
	int p = 0, n = 0;
	printf("Hallo! Welcome to coursework project of Nosov Alexander M8O-111B-20\n");
	printf("You can choose:\n1) Play Player vs Player\n2) Play Player vs Computer(coming soon...)\n3) Load game(coming soon...)\n");
	printf("What do you want to choose?: ");
	scanf("%d", &n);
	if (flag_d)
	{
		fprintf(log_f, "\nHallo! Welcome to coursework project of Nosov Alexander M8O-111B-20\n");
		fprintf(log_f, "You can choose:\n1) Play Player vs Player\n2) Play Player vs Computer(coming soon...)\n3) Load game(coming soon...)\n");
		fprintf(log_f, "What do you want to choose?: ");
		fprintf(log_f, "%d\n", n);
	}
	return n;
}

int hit(int** field, FILE* log_f, int flag_d)
{
	int key = 0, ch = 0;;
	char col = 0, row = 0;
	getchar();
	printf("Choose point of attack: ");
	scanf("%c%c", &col, &row);
	if (flag_d)
	{
		fprintf(log_f, "Choose point of attack: ");
		fprintf(log_f, "%c", col);
		fprintf(log_f, "%c\n", row);
	}
	col = col - 97; // a - z
	row = row - 48; // 0 - 9
	while (key == 0)
		if (field[row][col] == 1)
		{
			field[row][col] += 2;
			key = 1;
		}
		else if (field[row][col] == 2)
		{
			field[row][col] += 2;
			key = 1;
			ch = 1;
		}
		else
		{
			printf("Error!\n");
		}
	return ch;
}

int wincheck(int** field, int r, int c)
{
	int winf = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			if (field[i][j] == 2)
				winf = 1;
	}
	if (winf == 0)
		return 1;
	return 0;
}
int pvp(int** lfield, int** rfield, int r, int c, FILE* log_f, int flag_d)
{
	int win = 0, key = 0, flag2 = 0;

	pvpprn(lfield, rfield, r, c);

	printf("Left player set ships\n");
	if (flag_d)
		fprintf(log_f, "Left player set ships\n");
	lship1(lfield, rfield, r, c);

	lship2(lfield, rfield, r, c);

	lship3(lfield, rfield, r, c);

	lship4(lfield, rfield, r, c);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	pvpprn(lfield, rfield, r, c);
	printf("Right player set ships\n");
	if (flag_d)
		fprintf(log_f, "Right player set ships\n");
	rship1(lfield, rfield, r, c);

	rship2(lfield, rfield, r, c);

	rship3(lfield, rfield, r, c);

	rship4(lfield, rfield, r, c);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	pvpprn(lfield, rfield, r, c);

	while (win == 0)
	{
		flag2 = 1;
		while ((flag2 == 1) && (win == 0))
		{
			printf("Left player attack\n");
			if (flag_d)
				fprintf(log_f, "Left player attack\n");
			flag2 = hit(rfield, log_f, flag_d);
			pvpprn(lfield, rfield, r, c);
			if (wincheck(rfield, r, c))
				win = 1;
		}
		if (win == 1)
		{
			printf("Left player win!\n");
			if (flag_d)
				fprintf(log_f, "Left player win!\n");
			prn(lfield, rfield, r, c);
			return 0;
		}
		flag2 = 1;
		while ((flag2 == 1) && (win == 0))
		{
			printf("Right player attack\n");
			if (flag_d)
				fprintf(log_f, "Right player attack\n");
			flag2 = hit(lfield, log_f, flag_d);
			pvpprn(lfield, rfield, r, c);
			if (wincheck(lfield, r, c))
				win = 1;
		}
		if (win == 1)
		{
			printf("Right player win!\n");
			if (flag_d)
				fprintf(log_f, "Right player win!\n");
			prn(lfield, rfield, r, c);
			return 0;
		}

	}
}