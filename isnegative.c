#include<stdio.h>
int isnegative(int x){
    return ~(x>>31)+1;
}


int main(int argc, char const *argv[])
{
    int x;
    scanf("%d",&x);
    printf("%i",isnegative(x));
    return 0;
}
