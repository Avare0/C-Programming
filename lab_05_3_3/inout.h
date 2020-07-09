#define N 10

typedef int matr_t[N][N];
typedef int arr_t[N];

int input(matr_t a, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void output(matr_t a, int rows, int columns) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void switch_rows(matr_t a, int n, int place)
{
    int tmpr;

    for (int j = 0; j < n; j++)
    {
        tmpr = a[place][j];
        a[place][j] = a[place + 1][j];
        a[place + 1][j] = tmpr;
    }
}