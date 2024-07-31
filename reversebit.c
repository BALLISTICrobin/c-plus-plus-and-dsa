#include<stdio.h>

int main(int argc, char const *argv[])
{
    int x;
    scanf("%d",&x);
    int i=30;
    int mask = 1<<i;
    mask = mask^x;
    int mask1;
    i--;
    while(i>=0){
        mask1 = 1<<i;
    mask1 = mask1 ^ x;
    mask = mask | mask1;
    i--;
    }
    printf("%d",mask);
    return 0;
}
