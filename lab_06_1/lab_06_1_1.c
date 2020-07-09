#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strpbrk(char *string, char *find)
{
    for (int i = 0; i < strlen(string); i++)
        for (int j = 0; j < strlen(find); j++)
            if (string[i] == find[j])
                return &string[i];
    
    return NULL;
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

size_t my_strcspn(char *string, char *string2)
{
    int count = 0;
    int flag = 1;
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < strlen(string2); j++)
        {
            if (string[i] != string2[j])
                flag = 1;
            else
            {
                flag = 0;
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

char *my_strchr(char *string, char chr)
{
    int i = 0;

    while (i < strlen(string))
    {
        i++;
        if (string[i - 1] == chr)
            return &string[i - 1];
    }
    if (string[i] == chr)
        return &string[i];

    return NULL;
}

char *my_strrchr(char *string, char chr)
{
    int i = 0;
    char *s = NULL;

    while (i < strlen(string))
    {
        i++;
        if (string[i - 1] == chr)
            s = &string[i - 1];
    }
    if (string[i] == chr)
        s = &string[i];

    return s;
}

int main()
{
        //strspn
    printf("strcspn1: %d\n", my_strcspn("", "") == strcspn("", ""));
    printf("strcspn2: %d\n", my_strcspn("", "1") == strcspn("", "1"));
    printf("strcspn3: %d\n", my_strcspn("1", "") == strcspn("1", ""));
    printf("strcspn4: %d\n", my_strcspn("12345", "123") == strcspn("12345", "123"));
    printf("strcspn5: %d\n", my_strcspn("1AGGFDG5", "54321") == strcspn("12345", "54321"));
    printf("strcspn6: %d\n", my_strcspn("asdfasdfASDFASAAA", "A") == strcspn("AAAAdf AA", "A"));
    printf("strcspn7: %d\n", my_strcspn("AAHGFHDhfdgh A;';';SH BBasasdfsf", "A B") == strcspn("AAafgdfsg BBBB", "Asdfgh B"));
    printf("strcspn8: %d\n", my_strcspn("AASDFSFd SDFGHhn", "eyuioaEYUIOA") == strcspn("And my name is John", "eyuioaEYUIOA"));
    printf("strcspn9: %d\n\n", my_strcspn("and HFHDFGHDGH john", " qwADFasdasdcvbnm") == strcspn("and my name is john", " qwertyuiopasdfghjklzxcvbnm"));

    printf("strcspn1: %d\n", my_strpbrk("", "") == strpbrk("", ""));
    printf("strcspn2: %d\n", my_strpbrk("12124ASDASD5", "") == strpbrk("12345", ""));
    printf("strcspn3: %d\n", my_strpbrk("12345", "6") == strpbrk("12345", "6"));
    printf("strcspn4: %d\n", my_strpbrk("\n", "\n") == strpbrk("\n", "\n"));
    printf("strcspn5: %d\n", my_strpbrk("0132455", "5") == strpbrk("012345", "5"));
    printf("strcspn6: %d\n", my_strpbrk("SDasd545", "0") == strpbrk("012345", "0"));
    printf("strcspn7: %d\n", my_strpbrk("01sdfasdf5", "3") == strpbrk("012345", "3"));
    printf("strcspn8: %d\n", my_strpbrk("012asdfgfdsgh5", "543210") == my_strpbrk("012345", "543210"));
    printf("strcspn9: %d\n\n", my_strpbrk("Система", "c") == strpbrk("Система", "c"));

    printf("strspn1: %d\n", my_strspn("", "") == strspn("", ""));
    printf("strspn2: %d\n", my_strspn("", "1") == strspn("", "1"));
    printf("strspn3: %d\n", my_strspn("1", "") == strspn("1", ""));
    printf("strspn4: %d\n", my_strspn("12345", "123") == strspn("12asdfsdf5", "123"));
    printf("strspn5: %d\n", my_strspn("asdfsdaf5", "54321") == strspn("12345", "54321"));
    printf("strspn6: %d\n", my_strspn("AAAfdghdfghAA", "A") == strspn("AasfsafAAAA", "A"));
    printf("strspn7: %d\n", my_strspn("AAAAhdghfdBB", "A B") == strspn("AAhgfdhgfhBBB", "A B"));
    printf("strspn8: %d\n", my_strspn("And asdf is John", "eyuioaEYUIOA") == strspn("And myhgfdhis John", "eyasdfsfYUIOA"));
    printf("strspn9: %d\n\n", my_strspn("and my name is john", " qwertyuiopasasdflzxcvbnm") == strspn("and my namhdfghfdghs john", " qwertyuiopasdfghjklzxcvbnm"));

    printf("strchr1: %d\n", my_strrchr("", '\0') == strchr("", '\0'));
    printf("strchr2: %d\n", my_strrchr("012123r5dsfasdf345", '\0') == strrchr("0hfghdg", '\0'));
    printf("strchr3: %d\n", my_strrchr("012asdf345", '5') == strrchr("01asdfasd5", '5'));
    printf("strchr4: %d\n", my_strrchr("0asdfsdf45", '0') == strrchr("01asdfsf5", '0'));
    printf("strchr5: %d\n", my_strrchr("12gfdgdsg.34321", '.') == strrchr("12343.34321", '.'));
    printf("strchr6: %d\n", my_strrchr("bbbAhgfda", 'R') == strrchr("bgdgsfgAaaa", 'R'));
    printf("strchr7: %d\n", my_strrchr("bbbasdfasdfaaa", 'A') == strrchr("bbbasdfsdgaaa", 'A'));

    printf("strchr1: %d\n", my_strchr("", '\0') == strchr("", '\0'));
    printf("strchr2: %d\n", my_strchr("0adasd45", '\0') == strchr("012345", '\0'));
    printf("strchr3: %d\n", my_strchr("asdfsg5", '5') == strchr("012345", '5'));
    printf("strchr4: %d\n", my_strchr("01wertwer5", '0') == strchr("012345", '0'));
    printf("strchr5: %d\n", my_strchr("12343.34321", '.') == strchr("123asdfsdf4321", '.'));
    printf("strchr6: %d\n", my_strchr("bgfdsgsdfgaaa", 'R') == strchr("bbgdsgsdfAaaa", 'R'));
    printf("strchr7: %d\n", my_strchr("bbbAAaaa", 'A') == strchr("bbbgfhdghaaa", 'A'));



    return EXIT_SUCCESS;
}
