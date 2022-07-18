#include <stdio.h>


void pveprn(int** lfield, int** rfield, int r, int c)
{
	printf("  ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	printf("                   ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (lfield[i][j] == 1)
				printf("# ");
			else if (lfield[i][j] == 2)
				printf("%c ", -2);

		printf("                 ");
		printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (rfield[i][j] == 1)
				printf("# ");
			else if (rfield[i][j] == 2)
				printf("# ");
		printf("\n");
	}
	printf("\n\n\n");
}


void pvpprn(int** lfield, int** rfield, int r, int c)
{
	if (r < 10)
		printf("  ");
	else
		printf("   ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	if (r < 10)
		printf("                   ");
	else
		printf("                    ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (lfield[i][j] == 1)
				printf("# ");
			else if (lfield[i][j] == 2)
				printf("# ");
			else if (lfield[i][j] == 3)
				printf("O ");
			else if ((lfield[i][j] == 4) && ((lfield[i - 1][j] == 2) || (lfield[i + 1][j] == 2) || (lfield[i][j - 1] == 2) || (lfield[i][j + 1] == 2)))
				printf("X ");
			else if (lfield[i][j] == 4)
				printf("+ ");

		printf("                 ");
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (rfield[i][j] == 1)
				printf("# ");
			else if (rfield[i][j] == 2)
				printf("# ");
			else if (rfield[i][j] == 3)
				printf("O ");
			else if ((rfield[i][j] == 4) && ((rfield[i - 1][j] == 2) || (rfield[i + 1][j] == 2) || (rfield[i][j - 1] == 2) || (rfield[i][j + 1] == 2)))
				printf("X ");
			else if (rfield[i][j] == 4)
				printf("+ ");
		printf("\n");
	}
	printf("\n\n\n");
}

void rprn(int** lfield, int** rfield, int r, int c)
{
	if (r < 10)
		printf("  ");
	else
		printf("   ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	if (r < 10)
		printf("                   ");
	else
		printf("                    ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (lfield[i][j] == 1)
				printf("# ");
			else if (lfield[i][j] == 2)
				printf("# ");
			else if (lfield[i][j] == 3)
				printf("O ");
			else if ((lfield[i][j] == 4) && ((lfield[i - 1][j] == 2) || (lfield[i + 1][j] == 2) || (lfield[i][j - 1] == 2) || (lfield[i][j + 1] == 2)))
				printf("X ");
			else if (lfield[i][j] == 4)
				printf("+ ");

		printf("                 ");
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (rfield[i][j] == 1)
				printf("# ");
			else if (rfield[i][j] == 2)
				printf("%c ", -2);
			else if (rfield[i][j] == 3)
				printf("O ");
			else if ((rfield[i][j] == 4) && ((rfield[i - 1][j] == 2) || (rfield[i + 1][j] == 2) || (rfield[i][j - 1] == 2) || (rfield[i][j + 1] == 2)))
				printf("X ");
			else if (rfield[i][j] == 4)
				printf("+ ");
		printf("\n");
	}
	printf("\n\n\n");
}

void prn(int** lfield, int** rfield, int r, int c)
{
	if (r < 10)
		printf("  ");
	else
		printf("   ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	if (r < 10)
		printf("                   ");
	else
		printf("                    ");
	for (char z = 65; z < 65 + c; z++)
		printf("%c ", z);
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (lfield[i][j] == 1)
				printf("# ");
			else if (lfield[i][j] == 2)
				printf("%c ", -2);
			else if (lfield[i][j] == 3)
				printf("O ");
			else if ((lfield[i][j] == 4) && ((lfield[i - 1][j] == 2) || (lfield[i + 1][j] == 2) || (lfield[i][j - 1] == 2) || (lfield[i][j + 1] == 2)))
				printf("X ");
			else if (lfield[i][j] == 4)
				printf("+ ");

		printf("                 ");
		if (r > 10)
		{
			if (i < 10)
				printf("%d  ", i);
			else
				printf("%d ", i);
		}
		else
			printf("%d ", i);
		for (int j = 0; j < c; j++)
			if (rfield[i][j] == 1)
				printf("# ");
			else if (rfield[i][j] == 2)
				printf("%c ", -2);
			else if (rfield[i][j] == 3)
				printf("O ");
			else if ((rfield[i][j] == 4) && ((rfield[i - 1][j] == 2) || (rfield[i + 1][j] == 2) || (rfield[i][j - 1] == 2) || (rfield[i][j + 1] == 2)))
				printf("X ");
			else if (rfield[i][j] == 4)
				printf("+ ");
		printf("\n");
	}
	printf("\n\n\n");
}


void lship1(int** lfield, int** rfield, int r, int c)
{
	int n1 = 0;
	char row = 0, col = 0;
	printf("How much 1-length ship you want?: ");
	scanf("%d", &n1);
	for (int k = 0; k < n1; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		for (int i = 0; i < 1; i++)
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					lfield[row][col] += 1;
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					lfield[row][col] += 1;
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					lfield[row][col] += 1;
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					lfield[row][col] += 1;
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					lfield[row][col] += 1;
			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					lfield[row][col] += 1;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					lfield[row][col] += 1;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					lfield[row][col] += 1;
			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				lfield[row][col] += 1;
			else
			{
				printf("Error!\n");
				k--;
				continue;
			}
		prn(lfield, rfield, r, c);
	}
}

void lship2(int** lfield, int** rfield, int r, int c)
{
	int n2 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 2-length ship you want?: ");
	scanf("%d", &n2);
	for (int k = 0; k < n2; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 1))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row - i > 0)
							if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row - i > 0)
							if ((lfield[row - i - 1][col] == 1) && (lfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (row - i != 0)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					lfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row + i < r - 1)
							if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row + i < r - 1)
							if ((lfield[row + i + 1][col] == 1) && (lfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (row + i < r - 1)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					lfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (col + i < c - 1)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					lfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 1))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if ((lfield[row][col - i - 1] == 1) && (lfield[row + 1][col - i - 1] == 1) && (lfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (col - i > 0)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					lfield[row][col - i] += 1;
			else
			{
				prn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		prn(lfield, rfield, r, c);
	}
}



void lship3(int** lfield, int** rfield, int r, int c)
{
	int n3 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 3-length ship you want?: ");
	scanf("%d", &n3);
	for (int k = 0; k < n3; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row - i > 0)
							if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row - i > 0)
							if ((lfield[row - i - 1][col] == 1) && (lfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (row - i != 0)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					lfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row + i < r - 1)
							if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row + i < r - 1)
							if ((lfield[row + i + 1][col] == 1) && (lfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (row + i < r - 1)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					lfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (col + i < c - 1)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					lfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 2))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if ((lfield[row][col - i - 1] == 1) && (lfield[row + 1][col - i - 1] == 1) && (lfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (col - i > 0)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					lfield[row][col - i] += 1;
			else
			{
				prn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		prn(lfield, rfield, r, c);
	}
}



void lship4(int** lfield, int** rfield, int r, int c)
{
	int n4 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 4-length ship you want?: ");
	scanf("%d", &n4);
	for (int k = 0; k < n4; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row - i > 0)
							if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row - i > 0)
							if ((lfield[row - i - 1][col] == 1) && (lfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (row - i != 0)
						if (((lfield[row - i - 1][col] == 1)) && ((lfield[row - i - 1][col - 1] == 1)) && ((lfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					lfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 4))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row + i < r - 1)
							if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row + i < r - 1)
							if ((lfield[row + i + 1][col] == 1) && (lfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (row + i < r - 1)
						if (((lfield[row + i + 1][col] == 1)) && ((lfield[row + i + 1][col - 1] == 1)) && ((lfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					lfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (col + i < c - 1)
						if (((lfield[row][col + i + 1] == 1)) && ((lfield[row - 1][col + i + 1] == 1)) && ((lfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					lfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 3))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if ((lfield[row][col - i - 1] == 1) && (lfield[row + 1][col - i - 1] == 1) && (lfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((lfield[row][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
					&& (lfield[row - 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((lfield[row][col] == 1) && (lfield[row - 1][col] == 1) && (lfield[row + 1][col] == 1) && (lfield[row][col - 1] == 1) && (lfield[row][col + 1] == 1)
				&& (lfield[row - 1][col - 1] == 1) && (lfield[row + 1][col + 1] == 1) && (lfield[row + 1][col - 1] == 1) && (lfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (col - i > 0)
						if (((lfield[row][col - i - 1] == 1)) && ((lfield[row - 1][col - i - 1] == 1)) && ((lfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					lfield[row][col - i] += 1;
			else
			{
				prn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		prn(lfield, rfield, r, c);
	}
}






void rship1(int** lfield, int** rfield, int r, int c)
{
	int n1 = 0;
	char row = 0, col = 0;
	printf("How much 1-length ship you want?: ");
	scanf("%d", &n1);
	for (int k = 0; k < n1; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		for (int i = 0; i < 1; i++)
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					rfield[row][col] += 1;
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					rfield[row][col] += 1;
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					rfield[row][col] += 1;
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					rfield[row][col] += 1;
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					rfield[row][col] += 1;
			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					rfield[row][col] += 1;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					rfield[row][col] += 1;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					rfield[row][col] += 1;
			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				rfield[row][col] += 1;
			else
			{
				printf("Error!\n");
				k--;
				continue;
			}
		rprn(lfield, rfield, r, c);
	}
}

void rship2(int** lfield, int** rfield, int r, int c)
{
	int n2 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 2-length ship you want?: ");
	scanf("%d", &n2);
	for (int k = 0; k < n2; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 1))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row - i > 0)
							if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row - i > 0)
							if ((rfield[row - i - 1][col] == 1) && (rfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (row - i != 0)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					rfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row + i < r - 1)
							if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (row + i < r - 1)
							if ((rfield[row + i + 1][col] == 1) && (rfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (row + i < r - 1)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					rfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (col + i < c - 1)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					rfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 1))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if ((rfield[row][col - i - 1] == 1) && (rfield[row + 1][col - i - 1] == 1) && (rfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 2; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 2; i++)
					if (col - i > 0)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 1)
				for (int i = 0; i < 2; i++)
					rfield[row][col - i] += 1;
			else
			{
				rprn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		rprn(lfield, rfield, r, c);
	}
}



void rship3(int** lfield, int** rfield, int r, int c)
{
	int n3 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 3-length ship you want?: ");
	scanf("%d", &n3);
	for (int k = 0; k < n3; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 2))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row - i > 0)
							if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row - i > 0)
							if ((rfield[row - i - 1][col] == 1) && (rfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (row - i != 0)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					rfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row + i < r - 1)
							if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (row + i < r - 1)
							if ((rfield[row + i + 1][col] == 1) && (rfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (row + i < r - 1)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					rfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (col + i < c - 1)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					rfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 2))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if ((rfield[row][col - i - 1] == 1) && (rfield[row + 1][col - i - 1] == 1) && (rfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 3; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 3; i++)
					if (col - i > 0)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 2)
				for (int i = 0; i < 3; i++)
					rfield[row][col - i] += 1;
			else
			{
				rprn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		rprn(lfield, rfield, r, c);
	}
}



void rship4(int** lfield, int** rfield, int r, int c)
{
	int n4 = 0, flag1 = 0;
	char col = 0, row = 0, tnd = 0;
	printf("How much 4-length ship you want?: ");
	scanf("%d", &n4);
	for (int k = 0; k < n4; k++)
	{
		getchar();
		printf("Choose start of your ship: ");
		scanf("%c%c", &col, &row);
		col = col - 97; // a - z
		row = row - 48; // 0 - 9
		getchar();
		printf("Choose trend of your ship: ");
		scanf("%c", &tnd);
		if ((tnd == 'u') && (row >= 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row - i > 0)
							if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row - i > 0)
							if ((rfield[row - i - 1][col] == 1) && (rfield[row - i - 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (row - i != 0)
						if (((rfield[row - i - 1][col] == 1)) && ((rfield[row - i - 1][col - 1] == 1)) && ((rfield[row - i - 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row - i == 0)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					rfield[row - i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'd') && (row <= r - 4))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row + i < r - 1)
							if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (row + i < r - 1)
							if ((rfield[row + i + 1][col] == 1) && (rfield[row + i + 1][col - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (row + i < r - 1)
						if (((rfield[row + i + 1][col] == 1)) && ((rfield[row + i + 1][col - 1] == 1)) && ((rfield[row + i + 1][col + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (row + i == r - 1)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					rfield[row + i][col] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}

		else if ((tnd == 'r') && (col <= c - 3))
		{
			flag1 = 0;
			if ((col == 0) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == 0) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (row + i == r - 1)
							flag1++;

			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row + i][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col + i < c - 1)
							if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col + i == c - 1)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (col + i < c - 1)
						if (((rfield[row][col + i + 1] == 1)) && ((rfield[row - 1][col + i + 1] == 1)) && ((rfield[row + 1][col + i + 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col + i == c - 1)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					rfield[row][col + i] += 1;
			else
			{
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else if ((tnd == 'l') && (col >= 3))
		{
			flag1 = 0;
			if ((col == c - 1) && (row == 0))
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if ((col == c - 1) && (row == r - 1))
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
			}
			else if (col == c - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if ((rfield[row][col - i - 1] == 1) && (rfield[row + 1][col - i - 1] == 1) && (rfield[row - 1][col - i - 1] == 1))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == 0)
			{
				if ((rfield[row][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row + i][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;
			}
			else if (row == r - 1)
			{
				if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
					&& (rfield[row - 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
					for (int i = 1; i < 4; i++)
						if (col - i > 0)
							if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)))
							{
								flag1 += 1;
							}
							else {}
						else if (col - i == 0)
							flag1++;

			}
			else if ((rfield[row][col] == 1) && (rfield[row - 1][col] == 1) && (rfield[row + 1][col] == 1) && (rfield[row][col - 1] == 1) && (rfield[row][col + 1] == 1)
				&& (rfield[row - 1][col - 1] == 1) && (rfield[row + 1][col + 1] == 1) && (rfield[row + 1][col - 1] == 1) && (rfield[row - 1][col + 1] == 1))
				for (int i = 1; i < 4; i++)
					if (col - i > 0)
						if (((rfield[row][col - i - 1] == 1)) && ((rfield[row - 1][col - i - 1] == 1)) && ((rfield[row + 1][col - i - 1] == 1)))
						{
							flag1 += 1;
						}
						else {}
					else if (col - i == 0)
						flag1++;
			if (flag1 == 3)
				for (int i = 0; i < 4; i++)
					rfield[row][col - i] += 1;
			else
			{
				rprn(lfield, rfield, r, c);
				printf("Error!\n");
				flag1 += 1;
				k--;
				continue;
			}
		}
		else
		{
			printf("Error!\n");
			k--;
		}
		rprn(lfield, rfield, r, c);
	}
}
