#ifndef cdio_h
#define cdio_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    char *name;
    struct date {
        int day;
        int month;
        int year;
    } date;
    double *a;
} DATA;
void free_arr(DATA **info, int length);
void realloc_arr_for_avg(DATA **info, int n);
void find_average(DATA *info, int n);
int my_strlen(char *s);
int compare_dates(struct date one, struct date two);
void delete_rows (DATA **info, int *n);
void output(DATA *info, int length);
char *my_strpbrk(char *string, char *find);
int input(DATA **info);
int sort(DATA *info, int length, char *value);
int check_date(struct date *info);
int parce_date(char *date_str, DATA *info, int i);
size_t my_strspn(char *string, char *string2);

#endif /* cdio_h */
