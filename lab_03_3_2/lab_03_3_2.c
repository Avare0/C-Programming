#include <stdio.h>
#define N 1024
#include <math.h>
#include <stdlib.h>

int process(FILE* f)
{
    double a;
    double sum = 0;
    int n = 0;
    int flag1 = -1;
    int repeat = fscanf(f, "%lf", &a);
    fseek(f, 0, 0);

    while (fscanf(f, "%lf", &a) > 0)
    {
        if (a == repeat && flag1)
            flag1 = 1;
        else
            flag1 = 0;
        sum += a;
        n++;
    }
    fseek(f, 0, 0);

    if (n == 0)
        return -1;

    if (flag1)
        return 1;

    double avg = sum / n;
    double sum_disp = 0;

    while (fscanf(f, "%lf", &a) > 0)
        sum_disp += (a - avg) * (a - avg);

    fseek(f, 0, 0);
    double disp = sum_disp / n;

    double delta = sqrt(disp);

    int flag = 0;

    while (fscanf(f, "%lf", &a) > 0)
    {
        if (a > avg - 3 * delta && a < avg + 3 * delta)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main(int argc, char **argv)
{
    if (argc > 2 || argc < 2)
        return EXIT_FAILURE;
    FILE* f = fopen(argv[1], "r");
    int result = process(f);
    if (result == -1)
        return EXIT_FAILURE;
    printf("%d", result);
    fclose(f);
    return EXIT_SUCCESS;
}
