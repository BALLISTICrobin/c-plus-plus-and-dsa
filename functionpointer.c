#include<stdio.h>
#include<ctype.h>
#include<string.h>
int checkVowels(char ch){
    ch= tolower(ch);
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return 1;
    else 
    return 0;
}
void countVowels(char *str,int (*ptr)(char)){
    int count=0;
    for(int i=0; i<strlen(str); i++){
        if(ptr(str[i]))
        count++;
    }
    printf("%d",count);
}

int main()
{
    char str[100];
    fgets(str,100,stdin);
    countVowels(str,checkVowels);
}