#include<stdio.h>

void swapSwag(int *a,int *b){
int t= *a;
int p= *b;
t^=p;
p^=t;
t^=p;
printf("%d %d\n",t,p);
}
int main(){
    int a,b;
 printf("enter : ");
 scanf("%d %d",&a,&b);
 swapSwag(&a,&b);

    return 0;
}