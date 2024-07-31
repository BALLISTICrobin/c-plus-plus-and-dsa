#include<stdio.h>
#include<string.h>
typedef struct student{
    int id;
    char name[10];

}stu;
void swap(char *str1, char *str2){
char temp[10];
        strcpy(temp,str1);
        strcpy(str1,str2);
        strcpy(str2,temp);

}
stu students[50];

int main(){
    int count = 0;
    printf("enter: ");
for(int i=0; i<=5; i++){
    scanf("%s %d",students[i].name,&students[i].id);
    count++;
}
for(int i=0; i<count-1; i++){
for(int j=0; j<count-i; j++){
    if(strcmp(students[j].name,students[j+1].name)>=0){
        swap(students[j].name,students[j+1].name);
        
    }
    else if(strcmp(students[j].name,students[j+1].name)==0 )
    {
       if(students[j].id>=students[j+1].id){
        swap(students[j].name,students[j+1].name);
       }
    }
}
}
for(int i=0; i<count; i++){
    printf("%s\n",students[i].name);
}

}