#include<stdio.h>
#include<stdlib.h>
typedef struct stdid{
    unsigned int sl: 9;
    unsigned int dept: 9;
    unsigned int year: 13;
    unsigned int unused: 1;
}stdid;

typedef struct student{
    char name[50];
    stdid id;
}std;


int main(int argc, char const *argv[])
{
    int n;
    printf("enter number of students: ");
    scanf("%d",&n);
    std *log = (std*)malloc(n*sizeof(std));
    for(int i=0; i<n; i++){
        int yr,dc,sn,ide,iden;
        printf("enter name: ");
        scanf("%s",log[i].name);
        printf("enter id: ");
        scanf("%i",&iden);
        unsigned int ide = iden/1;
        sn = ide%1000;
        ide = ide/1000;
        dc = ide%100;
        yr = ide/100;

        log[i].id.year = yr;
        log[i].id.dept = dc;
        log[i].id.sl = sn;
        log[i].id.unused = 0;
    }
    for(int i=0; i<n; i++){
        printf("enter number %d student: ",i);
        log[i].id.year = log[i].id.year | 2000;
        unsigned nyear = log[i].id.year<<(9+9-1);
        unsigned ndept =
    }
    


    return 0;
}
