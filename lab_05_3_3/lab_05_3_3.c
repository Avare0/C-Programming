#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "inout.h"

int main()
{
    int a[N][N];
    int min[N];
    int min_row;
    int tmp = 0;
    int rows, columns;

    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 10)
        return EXIT_FAILURE;
    
    if (scanf("%d", &columns) != 1 || columns < 1 || columns > 10)
        return EXIT_FAILURE;

    if (input(a, rows, columns))
        return EXIT_FAILURE;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j == 0)
            {
                min_row = a[i][j];
                continue;
            }

            if (min_row > a[i][j])
                min_row = a[i][j];
        }
        min[i] = min_row;
    }

    for (int i = 0 ; i < rows - 1; i++)
        for (int j = 0 ; j < rows - i - 1 ; j++)
            if (min[j] < min[j + 1]) 
            {           
                tmp = min[j];
                min[j] = min[j + 1];
                min[j + 1] = tmp;
                switch_rows(a, columns, j); 
            }

    output(a, rows, columns);
    system("PAUSE");
    return EXIT_SUCCESS;   
}