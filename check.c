#include<stdio.h>
struct test{
    unsigned int a:1,b:2,c:3; 
}x;

int main(int argc, char const *argv[])
{
    for(int i=0; i<8; i++){
        x.c=x.b=x.a=i;
        printf("%d %d %d",x.a,x.b,x.c);
    }
    return 0;
}
