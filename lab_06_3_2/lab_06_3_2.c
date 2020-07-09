#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 256

void insert_str(char *s, char s1_words[N]);
int strtowords(char *s, char *separators, char s1_words[N][N]);
int is_in_array(char *s, char printed[N][N], int l);
int check_two_words_in_string(char s1_words[N][N], int s1_words_len, char *str);

int strtowords(char *s, char *separators, char s1_words[N][N])
{
    int k = 0;
    int count = 0;
    int flag;
    char str[N];
    str[0] = '\0';

    if (s[strlen(s) - 1] != '\n')
        return EXIT_FAILURE;

    for (int i = 0; i < strlen(s) - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < strlen(separators); j++)
            if (s[i] == separators[j])
                flag = 1;

        if (!flag)
        {
            char a[2];
            a[0] = s[i];
            a[1] = '\0';
            strcat(str, a);
            count++;
        }
        else
        {
            insert_str(str, s1_words[k]);
            k++;
            str[0] = '\0';
            count = 0;
        }
        if (count > 16)
            return -1;
    }

    insert_str(str, s1_words[k]);
    k++;
    str[0] = '\0';

    return k;
}

void difference(char s1_words[N][N], char s2_words[N][N], int p, int s1_words_len, int s2_words_len, int l, char printed[N][N])
{
    int flag;
    if (p == 1)
    {
        for (int i = 0; i < s1_words_len; i++)
        {
            for (int j = 0; j < s2_words_len; j++)
            {
                if (strcmp(s1_words[i], s2_words[j]) != 0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag && strcmp(s1_words[i], "") != 0 && check_two_words_in_string(s1_words, s1_words_len, s1_words[i]))
            {
                printf("%s ", s1_words[i]);
                insert_str(s1_words[i], printed[l]);
                l++;
            }
        }
    }
    else
    {
        for (int i = 0; i < s2_words_len; i++)
        {
            for (int j = 0; j < s1_words_len; j++)
                if (strcmp(s1_words[j], s2_words[i]) != 0)
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
            if (flag && is_in_array(s2_words[i], printed, l) && strcmp(s2_words[i], "") != 0 && check_two_words_in_string(s2_words, s2_words_len, s2_words[i]))
            {
                printf("%s ", s2_words[i]);
                insert_str(s2_words[i], printed[l]);
                l++;
            }
        }
    }
}

void insert_str(char *s, char s1_words[N])
{
    int i;
    for (i = 0; i < strlen(s); i++)
        s1_words[i] = s[i];
    s1_words[i] = '\0';
}

int check_two_words_in_string(char s1_words[N][N], int s1_words_len, char *str)
{
    int count = 0;
    for (int i = 0; i < s1_words_len; i++)
        if (strcmp(s1_words[i], str) == 0)
            count++;
    if (count > 1)
        return 0;

    return 1;
}

int is_in_array(char *s, char printed[N][N], int l)
{
    for (int i = 0; i < l; i++)
        if (strcmp(s, printed[i]) == 0)
            return 0;
    return 1;
}

int main() 
{
    char printed[N][N];
    char s1[N], s1_words[N][N];
    char s2[N], s2_words[N][N];
    int l = 0;
    char *separators = " ,;:-.!?";
    int p = 1;

    if (fgets(s1, 256, stdin) == NULL || fgets(s2, 256, stdin) == NULL)
        return EXIT_FAILURE;

    int s1_words_len = strtowords(s1, separators, s1_words);
    int s2_words_len = strtowords(s2, separators, s2_words);

    if (s1_words_len <= 1 || s2_words_len <= 1)
        return EXIT_FAILURE;

    printf("Result:");
    difference(s1_words, s2_words, p, s1_words_len, s2_words_len, l, printed);
    p++;
    difference(s1_words, s2_words, p, s1_words_len, s2_words_len, l, printed);

    return EXIT_SUCCESS;
}
