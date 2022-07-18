#include <stdio.h>
#include <string.h>

void input_arr(int* a)
{
	int r = 0, i = 0, j = 0, num = 0;
	char buf[500];
	printf("Input your array: ");
	getchar();
	fgets(buf, 500, stdin);
	for (int k = 0; k < 499; k++)
	{
		if (buf[k] == ']')
			r++;
	}
	for (int k = 0; k < 499; k++)
	{
		if (buf[k] == '[')
			r++;
	}
	for (int k = 0; k < 499; k++)
	{
		if (buf[k] == '[')
			for (int k = 0; k < 499; k++)
				if (buf[k] == ']')
					r++;
	}
	for (int k = 0; k < 499; k++)
	{
		if ((buf[k] == ']') && (buf[k + 1] != '\n'))
			r++;
	}


	if (r != 3)
	{
		printf("Incorrect input!\n");
		return -1;
	}
	while (buf[i - 1] != ']')
	{
		if ((buf[i] != ',') && (buf[i] != ' ') && (buf[i] != '[') && (buf[i] != ']') && ((buf[i] < '0') || (buf[i] > '9')))
		{
			printf("Incorrect input!\n");
			return -1;
		}
		if ((buf[i] == ',') && (buf[i + 1] != ' '))
		{
			printf("Incorrect input!\n");
			return -1;
		}
		if ((buf[i] != ',') && (buf[i] >= '0') && (buf[i] <= '9'))
		{
			num = (num * 10) + (buf[i] - '0');
		}
		else if (((buf[i] == ',') && (buf[i + 1] == ' ')) || (buf[i] == ']'))
		{
			a[j] = num;
			num = 0;
			j++;
		}
		i++;
	}
	return j;
}



void output_arr(int* a, int n)
{
	int k = 0;
	printf("[");
	for (k = 0; k < n - 1; k++)
	{
		printf("%d", a[k]);
		printf(", ");
	}
	printf("%d]\n", a[k]);
}



void bubble_sort(int* a, int n)
{
	int buf;
	char show = 'f';
	printf("You want to see an execution process?(t -True, f - False): ");
	getchar();
	scanf_s("%c", &show);
	if ((show != 't') && (show != 'f'))
	{
		printf("Incorrect input!");
		return -1;

	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
			{
				if (show == 't')
					output_arr(a, n);
				buf = a[j + 1];
				a[j + 1] = a[j];
				a[j] = buf;
			}
}



void insertion_sort(int* a, int n)
{
	int k = 0, buf = 0;
	char show = 'f';
	printf("You want to see an execution process?(t -True, f - False): ");
	getchar();
	scanf_s("%c", &show);
	if ((show != 't') && (show != 'f'))
	{
		printf("Incorrect input!");
		return -1;

	}
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0; j--)
			if (a[j - 1] > a[j])
			{
				if (show == 't')
					output_arr(a, n);
				k++;
				buf = a[j - 1];
				a[j - 1] = a[j];
				a[j] = buf;
			}
}



void quick_sort(int* a, int first, int last, char print, int n)
{
	if (first < last)
	{
		int left = first, right = last, middle = a[(left + right) / 2];
		if (print == 't')
			output_arr(a, n);
		while (left <= right)
		{
			while (a[left] < middle) left++;
			while (a[right] > middle) right--;
			if (left <= right)
			{
				int tmp = a[left];
				a[left] = a[right];
				a[right] = tmp;
				left++;
				right--;
			}
		}

		quick_sort(a, first, right, print, n);
		quick_sort(a, left, last, print, n);
	}
}