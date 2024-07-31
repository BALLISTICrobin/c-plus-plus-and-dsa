#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char *s;
    scanf("%[^\n]",s);
    char *substr;
    scanf("%s",substr);
    int len = strlen(substr);
    char *pos = strstr(s,substr);
    if(pos==NULL)
    printf("there is no substring");
    else
    printf("the position of substring is: %ld",pos-s);
    
    return 0;
}
