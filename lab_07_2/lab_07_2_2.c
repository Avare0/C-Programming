#include <stdio.h>
#include <stdlib.h>
#define N 200
#include <string.h>

int check(char *s, char *str);

struct product
{
    char name[31];
    char manufacturer[17];
    unsigned int price;
    unsigned int quantity;
};

int solve(char *file, struct product *t, char *str)
{
    int flag = 1;
    int count = 1;
    int count1 = 0;

    FILE *f = fopen(file, "rb");

    if (!f)
        return EXIT_FAILURE;

    while (flag)
    {
        if (!fread(t, sizeof(struct product), 1, f))
        {
            break;
        }

        count1++;

        if (check(t->name, str))
        {
            printf("%s\n%s\n%u\n%u\n", t->name, t->manufacturer, t->price, t->quantity);
            count = 0;
        }
    }

    fclose(f);

    if (count || count1 == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int check(char *s, char *str)
{
    int i = strlen(str) - 1;
    int j = strlen(s) - 1;

    while (i > -1 && j > -1 && str[i] == s[j])
    {
        i--;
        j--;
    }

    if (i == -1)
        return 1;

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 53;

    struct product t;

    if (strcmp(argv[1], "fb") != 0)
        return 53;

    if (solve(argv[2], &t, argv[3]))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
