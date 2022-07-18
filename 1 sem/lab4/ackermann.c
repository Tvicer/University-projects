#include <stdio.h>


long long int acker(int m, int n, char show)
{
	int a = 0;
	if (m == 0)
		a = n + 1;
	if ((m > 0) && (n == 0))
		a = acker(m - 1, 1, show);
	if ((m > 0) && (n > 0))
		a = acker(m - 1, acker(m, n - 1, show), show);
	if (show == 't')
		printf("m = %d, n = %d, a = %d\n", m, n, a);
	return a;
}
