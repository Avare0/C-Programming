#include <stdio.h>
#define N 100
#include <stdlib.h>
#include <string.h>

int process(FILE* f, int *countmax)
{
    int a;
    int length, number;
    if (fscanf(f, "%d", &number) != 1)
        return -2;
    else
        *countmax = 1;

    fseek(f, 0, 0);

    fscanf(f, "%d", &number);

    length = 0;

    fseek(f, 0, SEEK_SET);

    while (fscanf(f, "%d", &a) == 1)
    {
        if (a == number)
            length++;
        else
        {
            number = a;
            if (length > *countmax)
                *countmax = length;
            length = 1;
        }
    }
    if (length > *countmax)
        *countmax = length;

    return EXIT_SUCCESS;
}

int main()
{
    FILE* f = stdin;
    if (!f)
        return EXIT_FAILURE;
    int countmax = 0;
    if (process(f, &countmax))
        return EXIT_FAILURE;
    printf("%d", countmax);
    return EXIT_SUCCESS;
}
