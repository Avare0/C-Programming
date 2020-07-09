#include "cdio.h"

char *my_strpbrk(char *string, char *find)
{
    for (int i = 0; i < my_strlen(string); i++)
        for (int j = 0; j < my_strlen(find); j++)
            if (string[i] == find[j])
                return &string[i];
    
    return NULL;
}
int count_char(char *string, char s)
{
    int i = 0;
    int count = 0;
    while (string[i]) {
        if (string[i] == s)
            count++;
        i++;
    }
    return count;
}

int my_strlen(char *s)
{
    if (s == NULL)
        return 0;
    int i = 0;
    while (s[i])
        i += 1;
    return i;
}

size_t my_strspn(char *string, char *string2)
{
    if (strcmp(string2, "") == 0)
        return 0;
    int count = 0;
    int flag;
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < strlen(string2); j++)
        {
            if (string[i] != string2[j])
                flag = 0;
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            count += 1;
        else
            return count;
    }
    return count;
}

int check_date(struct date *info)
{
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (info->year % 4 == 0 && info->year % 100 != 0)
        a[1] = 29;
    if (info->month > 12)
        return EXIT_FAILURE;
    if (a[info->month - 1] < info->day || info->month > 12 || info->month <= 0 || info->day <= 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}


int parce_date(char *date_str, DATA *info, int i)
{
    if (count_char(date_str, '.') != 2)
        return EXIT_FAILURE;
    if (my_strspn(date_str, "0123456789.") != my_strlen(date_str))
        return EXIT_FAILURE;
    char *a = "";
    a = strtok(date_str, ".");
    if (my_strlen(a) != 2)
        return EXIT_FAILURE;
    info[i].date.day = atoi(a);
    a = strtok(NULL, ".");
    if (my_strlen(a) != 2)
        return EXIT_FAILURE;
    info[i].date.month = atoi(a);
    a = strtok(NULL, ".");
    if (my_strlen(a) != 4)
        return EXIT_FAILURE;
    info[i].date.year = atoi(a);
    if (check_date(&info->date))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int compare_dates(struct date one, struct date two)
{
    if (one.year > two.year)
        return 0;
    else if (one.year == two.year)
    {
        if (one.month > two.month)
            return 0;
        else if (one.month == two.month)
        {
            if (one.day > two.day)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    else
        return 1;
}

void delete_rows (DATA **info, int *n)
{
    struct date input = {1, 2, 1993};
    for (int i = 0; i < *n; i++)
    {
        if (compare_dates((*info)[i].date, input))
        {
            DATA tmp = (*info)[i];
            for (int j = i; j < *n - 1; j++)
                (*info)[j] = (*info)[j + 1];
            i--;
            *n -= 1;
            free(tmp.a);
            free(tmp.name);
            *info = realloc(*info, *n * sizeof(DATA));
        }
    }
}

void find_average(DATA *info, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 1; j < info[i].a[0] + 1; j++)
            sum += info[i].a[j];
        info[i].a[0] = sum / info[i].a[0];
    }
}

void realloc_arr_for_avg(DATA **info, int n)
{
    for (int i = 0; i < n; i++)
        (*info)[i].a = realloc((*info)[i].a, 2 * sizeof(double));
}

//void swap(DATA *info, int i)
//{
//    DATA tmp = info[i];
//    info[i] = info[i + 1];
//    info[i + 1] = tmp;
//}

int sort(DATA *info, int length, char *value)
{
    if (strcmp(value, "DATE") == 0)
    {
        int i = 0;
        DATA buf;
        char swap_cnt = 0;

        while (i < length)
        {
            if (i + 1 != length && compare_dates(info[i].date, info[i + 1].date) == 0)
            {
                buf = info[i];
                info[i] = info[i + 1];
                info[i + 1] = buf;
                swap_cnt = 1;
            }
            i++;
            if (i == length && swap_cnt == 1)
            {
                swap_cnt = 0;
                i = 0;
            }
        }
    }
    else if (strcmp(value, "TECHNICIAN") == 0)
    {
        int i = 0;
        DATA buf;
        char swap_cnt = 0;
        
        while (i < length)
        {
            if (i + 1 != length && strcmp(info[i].name,info[i + 1].name) > 0)
            {
                buf = info[i];
                info[i] = info[i + 1];
                info[i + 1] = buf;
                swap_cnt = 1;
            }
            i++;
            if (i == length && swap_cnt == 1)
            {
                swap_cnt = 0;
                i = 0;
            }
        }
    }
    else if (strcmp(value, "DATA") == 0)
    {
        int i = 0;
        DATA buf;
        char swap_cnt = 0;
        
        while (i < length)
        {
            if (i + 1 != length && 	info[i].a[0] > info[i + 1].a[0])
            {
                buf = info[i];
                info[i] = info[i + 1];
                info[i + 1] = buf;
                swap_cnt = 1;
            }
            i++;
            if (i == length && swap_cnt == 1)
            {
                swap_cnt = 0;
                i = 0;
            }
        }
    }
    else
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}


