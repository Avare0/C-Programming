#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arr.h"

//int input(arr_t a, int n)
//{
//    int count = 0;

//    for (int i = 0; i < n; i++)
//        if (scanf("%d", &a[i]) != 1)
//            return EXIT_FAILURE;
//        else
//            count += 1;
    
//    if (count != n)
//        return EXIT_FAILURE;

//    return EXIT_SUCCESS;
//}

int solve(arr_t a, int n, int *flag)
{
    int m = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > 0)
        {    
            m *= a[i];
            *flag += 1;
        };
    
    return m;
}

//void output(int res, int y)
//{
//    double answer = pow(res, 1.0 / y);
//    printf("%lf", answer);
//}

int main()
{
    int n, result;
    int flag = 0;

    
    if (scanf("%d", &n) != 1 || n < 1 || n > 10)
        return EXIT_FAILURE;

    int a[N];

    if (input(a, n))
        return EXIT_FAILURE;

    result = solve(a, n, &flag);

    if (flag != 0)
        output(result, flag);
    else
        return EXIT_FAILURE;
    
    // system("PAUSE");
    return EXIT_SUCCESS;
}
