#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ispos(int x){
   int mask = x>>31;
   (mask==0)? printf("-1") : printf("0");
}
//2's complement
int negate(int x){
    int mask = ~x;
    mask = mask|1;
    return mask;
}

int main(int argc, char const *argv[])
{
    int x;
    printf("enter");
    scanf("%d",&x);
    ispos(x);
    printf("%d",negate(x));
  
    return 0;
}
