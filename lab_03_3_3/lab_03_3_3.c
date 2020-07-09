#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int sorted(char *file, int length);
int get_number_by_pos(FILE *f, int position);
int amount_numbers(char *file);
void put_number_by_pos(FILE *f, int position, int number);
int output(char *file, int length);

int main(int argc, char **argv)
{
    if (argc != 3)
        return EXIT_FAILURE;


    if (strcmp(argv[1], "s") == 0)
    {
        int check = amount_numbers(argv[2]);
        if (check)
        {
            if (sorted(argv[2], check))
                return EXIT_FAILURE;
        }
        else
            return EXIT_FAILURE;
    }


    if (strcmp(argv[1], "p") == 0)
    {
        int check = amount_numbers(argv[2]);
        if (check)
        {
            if (output(argv[2], check))
                return EXIT_FAILURE;
        }
        else
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int amount_numbers(char *file)
{
    int num, length = 0;

    FILE *f = fopen(file, "rb");

    while (fread(&num, sizeof(int), 1, f) == 1)
        length++;

    fclose(f);

    return length;
}

void create_binary(char *file)
{
    FILE *f = fopen(file, "wb");

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int number = rand() % 50;
        fwrite(&number, sizeof(int), 1, f);
    }

    fclose(f);
}

int sorted(char *file, int length)
{
    int pos;

    FILE *f = fopen(file, "r + b");

    if (!f)
        return EXIT_FAILURE;

    for (int i = 0; i <= length; i++)
    {
        pos = i;
        for (int j = i + 1; j <= length; j++)
            if (get_number_by_pos(f, j) < get_number_by_pos(f, pos))
                pos = j;
        int tmp = get_number_by_pos(f, i);
        put_number_by_pos(f, i, get_number_by_pos(f, pos));
        put_number_by_pos(f, pos, tmp);
    }

    fclose(f);

    return EXIT_SUCCESS;
}

int output(char *file, int length)
{
    int num;

    FILE *f = fopen(file, "rb");

    if (!f)
        return EXIT_FAILURE;
    for (int i = 0; i < length; i++)
    {
        fread(&num, sizeof(int), 1, f);
        printf("%d ", num);
    }

    fclose(f);
    return EXIT_SUCCESS;
}


int get_number_by_pos(FILE *f, int position)
{
    int num;
    int pos = ftell(f);

    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, f);

    fseek(f, pos, SEEK_SET);

    return num;
}

void put_number_by_pos(FILE *f, int position, int value)
{
    int pos = ftell(f);

    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fwrite(&value, sizeof(int), 1, f);

    fseek(f, pos, SEEK_SET);
}
