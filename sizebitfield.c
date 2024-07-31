#include<stdio.h>
typedef struct bit{
    unsigned int a: 32,b:1;
}bit;

int main(int argc, char const *argv[])
{
    /* code */
    printf("%d",sizeof(bit));
    return 0;
}
