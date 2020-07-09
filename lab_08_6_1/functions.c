#include <stdio.h>
#include <math.h>

double u1(double *a, double *end)
{
    double sum = 0;
    int count = 0;
    
    for (size_t i = 0; a + i <= end; i++)
    {
        sum += a[i];
        count++;
    }
    
    return sum / count;
}

void find_max_diff(double *a, double *end, double u, int *imax1, int except1)
{
    double diff1 = 0;
    double diff = 0;
    
    for (size_t i = 0; a + i <= end; i++)
    {
        diff1 = fabs(u - *(a + i));
        if (diff1 > diff && i != except1)
        {
            diff = fabs(u - *(a + i));
            *imax1 = i;
        }
    }
}

void delete(double *a, double *end, int imax)
{
    for (size_t i = imax; a + i < end; i++)
        *(a + i) = *(a + i + 1);
}

void insert(double *a, double *end, size_t p, double u2)
{
    size_t i = 0;
    
    size_t l = p;
    
    while (end - i > a + l)
    {
        *(end - i) = *(end - i - 1);
        i++;
    }
    *(a + p) = u2;
}

double max_arr(double *a, double *end)
{
    double max = 0;
    for (size_t i = 0; a + i <= end; i++)
        if (*(a + i) > max)
            max = *(a + i);
    
    return max;
}

void move_1(double *a, double *end)
{
    for (size_t i = 0; end - i - 1 > a; i++)
        *(end - i - 1) = *(end - i - 2);
}
