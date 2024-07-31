#include<stdio.h>
int isParse(int num){
    for(int i=31; i>=1; i--){
        int mask1 = ((1<<i)&num)>>i;
        int mask2 = ((1<<(i-1))&num)>>(i-1);
        if(mask1==1 && mask2==1){
            return 0;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    unsigned int x;
    scanf("%u",&x);
    printf("%d",isParse(x));
    return 0;
}
