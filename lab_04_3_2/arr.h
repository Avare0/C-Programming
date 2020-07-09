#define N 10

typedef int arr_t[N];

int input(arr_t a, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return EXIT_FAILURE;
        else
            count += 1;
    
    if (count != n)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
