#include<stdio.h>
#include<string.h>
#define BUFFER_SIZE 100
int main(int argc, char const *argv[])
{
    int num_line;
    printf("enter number of line: ");
    scanf("%d",&num_line);
    getchar();
    int length[num_line];
    char *p,*q;
    char line[num_line][BUFFER_SIZE];
    for(int i=0; i<num_line; i++){
        
        printf("enter line no %d",i+1);
        fgets(line[i],BUFFER_SIZE,stdin);
        p=&line[i][0];
        q=&line[i][strlen(line[i])-1];
        while(*p==' '){
            p++;
        }
        while(*q==' '){
            q--;
        }
        length[i] = q-p;
        while(p<=q){
            printf("%c",*p);
            p++;
        }
        
        
        printf("\n");

    }
    int max = length[0];
     int index;
    for(int i=0; i<num_line; i++){
       
        if(length[i]>max){
            max = length[i];
            index = i;
        }
        
    }
    printf("\n%s",line[index]);
    

    return 0;
}
