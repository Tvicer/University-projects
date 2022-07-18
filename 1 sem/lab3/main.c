#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t = 0;
    while (t != 7)
    {
        printf("Hallo! Welcome to lab of Nosov Alexander!\nYou can choose this tasks:\n1) Calculate \"pi\"\n2) Find local maximums of array (already done)\n");
        printf("3) Find longest sequence in array\n4) Turn over all elements of array\n5) The Caesar Cipher\n6) Sort words in string\n7) Exit\n");
        printf("\n");
        printf("What do you want to choose?: ");
        scanf_s("%d", &t);
        printf("\n");
        while (getchar() != '\n');



        if ((t <= 0) || (t > 7))
        {
            printf("Task not found :(\n\n");
        }



        if (t == 7)
        {
            printf("See you soon :)");
            return 0;
        }



        if (t == 1)
        {
            double x = 0, h = 0, s = 0, pi = 0;
            printf("Enter your accuracy: ");
            scanf_s("%lf", &h);
            if ((h > 0) && (h < 1))
            {
                x = h;
                while (x < 1.0)
                {
                    s += 1.0 / (1.0 + x * x);
                    x += h;
                }
                pi = 2.0 * h * (1.5 + 2.0 * s);
                printf("Your value of \"pi\" is: %.20lf\n", pi);
                printf("You miss on: %.20lf\n\n", M_PI - pi);
            }
            else
                printf("Input error!\n\n");
        }



        if (t == 2)
        {
            printf("Already done\n\n");
        }


        if (t == 3)
        {
            /*int n = 0, mx = 0, k = 0;
            printf("Input in range of array: ");
            scanf_s("%d", &n);
            if (n <= 0)
            {
                printf("Input error!");
                return -1;
            }
            int* a, * b, * mxm;
            a = (int*)calloc(n, sizeof(int));
            b = (int*)calloc(n, sizeof(int));
            mxm = (int*)calloc(n, sizeof(int));
            for (int i = 0; i < n; i++)
            {
                printf("Input %d element of array: ", i + 1);
                scanf_s("%d", &a[i]);
            }
            for (int i = 0; i < n; i++)
            {
                b[i] = 0;
                mxm[i] = 0;
            }

            for (int j = 0; j < n; j++)
            {
                if (a[j] < a[j + 1])
                {
                    b[j] = a[j];
                    k++;
                }
                else
                {
                    if (k > mx)
                    {
                        b[j] = a[j];
                        for (int i = 0; i < n; i++)
                            mxm[i] = 0;
                        mx = k + 1;
                        for (int i = 0; i < n; i++)
                            mxm[i] = b[i];
                        for (int i = 0; i < n; i++)
                            b[i] = 0;
                        k = 0;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (mxm[i] != 0)
                    printf("%d ", mxm[i]);
            }
            printf("\n\n");*/


            int size, i = 1, maxsequence = 0, sequence = 0, i1 = 1, i2 = 1, j = 1;
            printf("Input size array: ");
            scanf_s("%d", &size);
            int *buf = (int*)calloc(size + 1, sizeof(int));
            buf[size + 1] = 0;

            for (i; i <= size; i++)
            {
                printf("Input %d element of array: ", i + 1);
                scanf_s("%d", &buf[i]);
            }
            printf("\n");

            for (i = 1; i <= size;)
            {
                if (buf[i] < buf[i + 1])
                {
                    i1 = i - sequence;
                    sequence++;
                    i++;
                }
                else if ((buf[i] >= buf[i + 1]) && (sequence >= maxsequence))
                {
                    sequence++;
                    i2 = i1;
                    maxsequence = sequence;
                    sequence = 0;
                    i++;
                }
                else
                {
                    sequence = 0;
                    i1 = 0;
                    i++;
                }
            }

            if (maxsequence >= sequence) // выводим максимальную по длине последовательность
            {
                printf("Maximum sequence in the array: ");
                while (maxsequence != 0)
                {
                    if (buf[i2] != 0)
                        printf(" %d ", buf[i2]);
                    maxsequence--;
                    i2++;
                }
            }

            else if (sequence >= maxsequence)
            {
                printf("Maximum sequence in the array: ");
                while (sequence != 0)
                {
                    if (buf[i1] != 0)
                        printf(" %d ", buf[i1]);
                    sequence--;
                    i1++;
                }
            }
            printf("\n\n");
        }



        if (t == 4)
        {
            int j = 0, m = 0, k = 0;
            int a[30];
            srand(time(NULL));
            for (int i = 0; i < 30; i++)
                a[i] = rand() % 99999 + 10;

            printf("Source array is: ");
            for (int i = 0; i < 30; i++)
                printf("%d ", a[i]);
            printf("\n");

            for (int i = 0; i < 30; i++)
            {
                m = 0;
                j = 10000;
                k = 1;
                for (int c = 0; c < 5; c++)
                {
                    if (a[i] / j == 0)
                        j /= 10;
                    else
                    {
                        m = m + a[i] / j % 10 * k;
                        j /= 10;
                        k *= 10;
                    }
                }
                a[i] = m;
            }

            printf("Reversed array is: ");
            for (int i = 0; i < 30; i++)
                printf("%d ", a[i]);

            printf("\n\n");
        }



        if (t == 5)
        {
            int k = 0;
            char st[100];
            for (int i = 0; i < 100; i++)
                st[i] = 0;
            printf("Enter your string (if you want to decrypt your string, add a key in first symbol): ");
            fgets(st, 100, stdin);
            if ((st[0] >= 48) && (st[0] <= 57))
            {
                k = st[0] - 48;
                st[0] = ' ';
                for (int i = 1; i < 100; i++)
                {
                    if (((st[i] >= 65) && (st[i] <= 90)) || ((st[i] >= 97) && (st[i] <= 122)))
                        if ((st[i] - k < 65) || ((st[i] >= 97) && (st[i] - k < 97)))
                            st[i] = st[i] - k + 26;
                        else
                            st[i] = st[i] - k;
                }
                printf("Decrypted string is:");
                puts(st);
            }
            else
            {
                srand(time(NULL));
                k = rand() % 9 + 1;
                for (int i = 0; i < 100; i++)
                {
                    if (((st[i] >= 65) && (st[i] <= 90)) || ((st[i] >= 97) && (st[i] <= 122)))
                        if (((st[i] + k > 90) && (st[i] <= 90)) || (st[i] + k > 122))
                            st[i] = st[i] + k - 26;
                        else
                            st[i] = st[i] + k;
                }
                printf("Encrypted string is: ");
                printf("%d", k);
                puts(st);
            }

            printf("\n\n");
        }



        if (t == 6)
        {
            int len1 = 0;
            char st[100];
            for (int i = 0; i < 100; i++)
                st[i] = 127;
            printf("Enter your string: ");
            fgets(st, 100, stdin);
            for (int len = 1; len < 100; len++)
            {
                for (int i = 0; i < 100; i++)
                {
                    if ((st[i] != ' ') && (st[i] != 127) && (st[i] != '\n'))
                        len1 += 1;
                    if (((st[i] == ' ') || (st[i] == '\n')) && (len == len1))
                    {
                        for (int j = i - len; j < i; j++)
                        {
                            printf("%c", st[j]);
                            st[j] = ' ';
                        }
                        len1 = 0;
                        printf("\n");
                    }
                    else if ((st[i] == ' ') || (st[i] == 0))
                        len1 = 0;
                }
            }

            printf("\n\n");
        }
    }
}
