#include<stdio.h>
int bitParity(int x){
    int count0=0;
    for(int i=31; i>=0; i--){
        int mask = ((1<<i)&x)>>i;
        if(mask ==0){
            count0++;
        }
    }
    if(count0%2!=0)
    return 1;
    else
    return 0;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d",&num);
    printf("%d",bitParity(num));
    return 0;
}
