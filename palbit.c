#include<stdio.h>
int palindrome(int x){
    int mask=0;
    int count  = 0,i;
    for(i=31; i>=16; i--){
        mask = mask|(((1<<i)&x)>>(i-count));
        count++;
    }
  int j =i;
    int count2=0;
    while(j>=0){
        mask = mask|(((1<<j)&x)<<(16-j+count2));
        count2++;
        j--;
    }
    return x^mask;
}


int main(int argc, char const *argv[])
{
    unsigned int x;
    scanf("%u",&x);
    printf("%d",palindrome(x));
    return 0;
}
