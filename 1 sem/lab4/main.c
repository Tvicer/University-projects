#include <stdio.h>
#include "Header.h"


int main()
{
	
	while (1)
	{
		int t = 0, e = 0;
		printf("Hello, it is a lab N4 of Nosov Alexander.\nYou can choose:\n1) Ackermann function\n2) Array sort\n3) Exit\nWhat do you want to choose?: ");
		scanf_s("%d", &t);
		if (t == 3)
		{
			printf("See you soon :)");
			return 0;
		}
		if ((t < 1) || (t > 2))
		{
			printf("Incorrect input!\n");
			e++;
		}
	
		if ((t == 1) && (e == 0))
		{
			int z = 0, m1 = 0, n1 = 0;
			char show = 'f';
			printf("Input your m: ");
			scanf_s("%d", &m1);
			printf("Input your n: ");
			scanf_s("%d", &n1);
			if ((m1 < 0) || (n1 < 0))
			{
				printf("Incorrect input!\n");
				e++;
			}
			printf("You want to see an execution process?(t -True, f - False): ");
			getchar();
			scanf_s("%c", &show);
			if ((show != 't') && (show != 'f'))
			{
				printf("Incorrect input!\n");
				e++;
			}
			z = acker(m1, n1, show);
			printf("%d\n", z);
		}
		
		if ((t == 2) && (e == 0))
		{
			int n = 0, l = 0, i = 0, h = 0;
			char show = 'f';
			e = 0;
			scanf_s("%d", &h);
			int* a;
			a = calloc(h, sizeof(int));
			n = input_arr(a);
			if (n == -1)
				e++;
			if (e == 0)
			{
				printf("How do you want to sort your array?:\n1) Bubble sort\n2) Insertion sort\n3) Quick_sort\nWhat do you want to choose?: ");
				scanf_s("%d", &t);
				if ((t < 1) || (t > 3))
				{
					printf("Incorrect input!");
					return -1;
				}
				if (t == 1)
					bubble_sort(a, n);
				if (t == 2)
					insertion_sort(a, n);
				if (t == 3)
				{	
					printf("You want to see an execution process?(t -True, f - False): ");
					getchar();
					scanf_s("%c", &show);
					if ((show != 't') && (show != 'f'))
					{
						printf("Incorrect input!");
						return -1;
					}
					quick_sort(a, 0, n - 1, show, n);
				}
				output_arr(a, n);
			}
		}
	}
}