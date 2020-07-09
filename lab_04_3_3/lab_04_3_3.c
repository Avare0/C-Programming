#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "arr.h"

int reversed(int num)
{
	int sum = 0;

	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
		if (num > 0)
		{
			if (sum >= INT_MAX / 10)
			{
				if (sum == INT_MAX / 10 && !(num % 10 <= 7))
					return -1;
			}
			else
		    	sum *= 10;
		}
	}
	
	return sum;
}

void insert(arr_t a, int place, int l)
{
	for (int i = l; i >= place; i--)
		a[i + 1] = a[i];

	a[place] = reversed(a[place - 1]);
}

int main()
{
	int flag = 1;
	int n;

	if (scanf("%d", &n) != 1)
		return EXIT_FAILURE;
	
	int a[N];

	if (input(a, n))
		return EXIT_FAILURE;
	
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
		{
			if (reversed(a[i]) != -1)
			{
				insert(a, i + 1, n);
				i++;
				n++;
				flag = 0;
			}
			else
				return EXIT_FAILURE;
		}

	if (flag)
		return EXIT_FAILURE;

	output(a, n);
	system("PAUSE");
	return EXIT_SUCCESS;
}
