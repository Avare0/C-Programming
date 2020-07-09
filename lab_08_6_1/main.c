#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cdio.h"

int main()
{
    int n;
    double *a;
    int p;
	puts("input:");
    if (scanf("%d", &n) != 1 || n < 1)
        return EXIT_FAILURE;
    
    a = (double*)malloc(n * sizeof(double));

    double *end = a + (n - 1);
    
    if (input(a, end))
	{
		free(a);
        return EXIT_FAILURE;
	}
    
    double average = u1(a, end);

	int imax1, imax2;
	imax1 = 0;
	imax2 = 0;
	
	find_max_diff(a, end, average, &imax1, -1);
	find_max_diff(a, end, average, &imax2, imax1);
	
    delete(a, end, imax1);

	if (imax2 > imax1)
		imax2 -= 1;
	delete(a, end - 1, imax2);
	
	end -= 2;
	
	if (end == a)
	{
		free(a);
		return EXIT_FAILURE;
	}
    
    if (scanf("%d", &p) != 1 || p > n - 3 || p < 0)
	{
		free(a);
		return EXIT_FAILURE;
	}
    double max = max_arr(a, end);
    insert(a, end + 1, p, max);
    a = (double*) realloc(a, (n + 1) * sizeof(double));
    end = a + n;
    move_1(a, end);
    
    *a = max;
    *(end) = max;

    output(a, end);
    
    free(a);
    return EXIT_SUCCESS;
}
