#include "cdio.h"

int main() {
    DATA *info = NULL;
    int length = input(&info);
    if (length <= 0)
    {
        free_arr(&info, length);
        return EXIT_FAILURE;
    }
    delete_rows(&info, &length);

    if (length == 0)
    {
        free_arr(&info, length);
        return EXIT_FAILURE;
    }
    find_average(info, length);
    realloc_arr_for_avg(&info, length);

    char key[20];
    scanf("%s", key);
    if (sort(info, length, key))
    {
        free_arr(&info, length);
        return EXIT_FAILURE;
    }
    output(info, length);
    free_arr(&info, length);
    
    return EXIT_SUCCESS;
}
