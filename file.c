#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

int checkParity(int n)
{
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}

int checkPalindrome(char *str)
{
    char comp[10];
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        comp[i] = str[len-i-1];
    }
    comp[len] = '\0';
    if (strcmp(comp, str) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    FILE *fp;
    fp = fopen("in.txt", "r");
    if (fp == NULL)
    {
        printf("error");
    }
    FILE *fpt;
    fpt = fopen("out.txt", "w");
    if (fpt == NULL)
    {
        printf("error");
    }
    while (!feof(fp))
    {
        char name[10];
        char id[10];
        fscanf(fp, "%s %s", name, id);
        int num = atoi(id);
        int z = checkParity(num);
        int x = checkPalindrome(name);
        if (x == 1 && z == 1)
        {
            fputs("palindrome ", fpt);
            fputs("even\n", fpt);
        }
        else if (x == 1 && z == 0)
        {
            fputs("palindrome ", fpt);
            fputs("odd\n", fpt);
        }
        else if (x == 0 && z == 1)
        {
            fputs("non palindrome ", fpt);
            fputs("even\n", fpt);
        }
        else if (x == 0 && z == 0)
        {
            fputs("non palindrome ", fpt);
            fputs("odd\n", fpt);
        }
    }
    return 0;
}