#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arr.h"
#define N 10
typedef double arr_d_t[N];

//int input(int *a, int n)
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

void nums(int p, arr_d_t numbers, int *j)
{
    while (p > 0)
    {
        numbers[*j] = p % 10;
        *j += 1;
        p /= 10;
    }
}

int main()
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > 10)
        return EXIT_FAILURE;

    int a[N];
    double numbers[N];
    int sum, j;
    int flag = 0;

    if (input(a, n) == 1)
		return EXIT_FAILURE;

    for (int i = 0; i < n ; i++)
    {
        sum = 0;
		j = 0;
        
		nums(a[i], numbers, &j);

        for (int k = 0; k < j; k++)
            sum += pow(numbers[k], j);

        if (sum == a[i] && a[i] != 0)
        {
            flag = 1;
            printf("%d ", a[i]);    
        }
    }

    if (flag == 0) 
        return EXIT_FAILURE;
    // system("PAUSE");
    return EXIT_SUCCESS;  
}
