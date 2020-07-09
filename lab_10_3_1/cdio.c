#include "cdio.h"

int input(DATA **info)
{
    
    *info = malloc(1);

    int len = 0;
    int length = 0;
    char name1[256];
    char date[20];
    
    while (1) {
        scanf("%s", date);
        if (strcmp(date, "00.00.0000") == 0)
            return length;
        *info = realloc(*info, (length + 1) * sizeof(DATA));
        length += 1;
        if (parce_date(date, *info, length - 1))
		{
//			free_arr(info, length);
			return -1;
		}
        scanf("%s", name1);
		if (strspn(name1,"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") != strlen(name1))
		{
//			free_arr(info, length);
			return -1;
		}
        (*info)[length - 1].name = malloc((int)strlen(name1) + 1);
        strcpy((*info)[length - 1].name, name1);
        if (scanf("%d", &len) != 1)
		{
//			free_arr(info, length);
			return -1;
		}
        if (len <= 0)
		{
//			free_arr(info, length);
			return -1;
		}
        (*info)[length - 1].a = malloc((len + 1) * sizeof(double));
        (*info)[length - 1].a[0] = len;
        for (int i = 1; i < len + 1; i++)
            if (scanf("%lf", &((*info)[length - 1].a[i])) != 1)
			{
//				free_arr(info, length);
				return -1;
			}
//         || (*info)[length - 1].a[i] < 0
    }

}


void output(DATA *info, int length)
{
    FILE* file = fopen("results.txt", "w");
    for (int i = 0; i < length; i++)
    {
        if (info[i].date.day < 10)
            fprintf(file, "0");
        fprintf(file, "%d.", info[i].date.day);
        if (info[i].date.month < 10)
            fprintf(file, "0");
        fprintf(file, "%d.%d\n%s\n", info[i].date.month, info[i].date.year, info[i].name);
        fprintf(file, "%d %lf\n", 1, info[i].a[0]);
    }
    fclose(file);
}

void free_arr(DATA **info, int length)
{
    for (int i = 0; i < length; i++)
    {
        free((*info)[i].a);
        free((*info)[i].name);
    }
    free(*info);
}
