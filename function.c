#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *dbl_dbl(char *str, char ch)
{
    int len = strlen(str);
    char *newstr = (char *)malloc(100 * sizeof(char));
    int i = 0;
    for (i; i < len / 2; i++)
    {
        newstr[i] = str[i];
    }
    newstr[i] = ch;

    i++;
    while (i <= len + 1)
    {
        newstr[i] = str[i - 1];
        if (i == len + 1)
            newstr[i] = ch;

        i++;
    }
    newstr[i] = '\0';

    return newstr;
}

int main()
{
    char str[100];
    char ch;
    printf("enter string: ");
    fgets(str, 100, stdin);
    printf("enter character: ");
    scanf("%c", &ch);
    char *newstr = dbl_dbl(str, ch);
    printf("%s\n", newstr);
    free(newstr);
    return 0;
}