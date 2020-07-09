#include <stdlib.h>
#include <stdio.h>
#include "inout.h"

void delete(matr_t a, int row, int *column, int pos)
{
    for (int i = 0; i < row; i++)
        for (int j = pos; j < *column - 1; j++)
            a[i][j] = a[i][j + 1];
    *column -= 1;
}

int is_innumber(int num, int number)
{
    if (number == 0 && num == 0)
        return 1;
    while (number > 0)
    {
        if (num == number % 10)
            return 1;
        number /= 10;
    }
    return 0;
}

int main()
{
    int rows, columns;
    int num;
    int a[N][N];
    
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 10)
        return EXIT_FAILURE;
    
    if (scanf("%d", &columns) != 1 || columns < 1 || columns > 10)
        return EXIT_FAILURE;

    if (input(a, rows, columns))
        return EXIT_FAILURE;

    if (scanf("%d", &num) != 1 || num < 0 || num > 9)
        return EXIT_FAILURE;

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
            if (is_innumber(num, abs(a[j][i])))
            {
                delete(a, rows, &columns, i);
                i -= 1;
                break;
            }
    }

    if (columns == 0)
        return EXIT_FAILURE;
    output(a, rows, columns);
    system("PAUSE");
    return EXIT_SUCCESS;
}