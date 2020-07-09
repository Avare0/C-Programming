#include <stdlib.h>
#include <stdio.h>
#include "inout.h"

typedef int row[N];

int mono(row a, int n, int i)
{
    int min;
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        if (j == 0)
        {
            min = a[j];
            continue;
        }

        if (j == 1)
        {
            if (a[j] > min)
                flag = 1; // Возрастающая или неизменяющаяся
            else if (a[j] < min)
                flag = 2; // Убывающая
            else
                flag = 3;
            min = a[j];
            continue;
        }

        if ((a[j] >= min && flag == 1) || (a[j] <= min && flag == 2) || (flag == 3))
        {
            if (flag == 3)
            {
                if (a[j] > min)
                    flag = 1;
                else if (a[j] != min)
                    flag = 2;
            }
            min = a[j];
        }
        else 
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()   
{
    int rows, columns;
    int a[N][N];
    int result[N];

    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 10)
        return EXIT_FAILURE;

    if (scanf("%d", &columns) != 1 || columns < 1 || columns > 10)
        return EXIT_FAILURE;

    if (input(a, rows, columns))
        return EXIT_FAILURE;

    for (int i = 0; i < rows; i++)
        if (mono(a[i], columns, i))
            result[i] = 1;
        else
            result[i] = 0;

    output(result, rows);
    system("PAUSE");
    return EXIT_SUCCESS;
}
