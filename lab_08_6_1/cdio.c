#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cdio.h"

int input(double *a, double *end)
{
    size_t i;
    for (i = 0; a + i <= end; i++)
        if (scanf("%lf", a + i) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output(double *a, double *end)
{
    size_t i = 0;
    while (a + i <= end)
    {
        printf("%lf ", *(a + i));
        i++;
    }
}
