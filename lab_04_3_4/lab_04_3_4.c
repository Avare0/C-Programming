#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arr.h"

void sort(arr_t a, int n)
{
	int i = 1;
	int b = 0;
	
	while (i < n)
		if (!(i) || a[i - 1] <= a[i])
			i += 1;
		else
		{
			b = a[i - 1];
			a[i - 1] = a[i];
			a[i] = b;
			i -= 1;
		}
}

//int input(arr_t a, int n)
//{
//	int count = 0;

//	for (int i = 0; i < n; i++)
//		if (scanf("%d", &a[i]) != 1)
//            return EXIT_FAILURE;
//        else
//            count += 1;

//    if (count != n)
//	{
//        return EXIT_FAILURE;
//	}
	
//	return EXIT_SUCCESS;
//}

int main()
{
	int n;

	if (scanf("%d", &n) != 1 || n < 1 || n > 10)
        	return EXIT_FAILURE;

	int a[N];
	
	if (input(a, n) == 1)
		return EXIT_FAILURE;
	
	sort(a, n);

	output(a, n);

	return EXIT_SUCCESS;
}
