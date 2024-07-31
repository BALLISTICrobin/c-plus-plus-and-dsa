#include<stdio.h>



int main(int argc, char const *argv[])
{
    int i=8, j=5, k;
    float x = 0.005, y=-0.01;
    char c='c', d= 'd';
    k = (float)((i-3*j) % ((int)c+2*(int)d))/(x-y);
    printf("%d",k);
    int *pa =&i;
    int *pb = pa;
    printf("%x",*pa);
    return 0;
}
