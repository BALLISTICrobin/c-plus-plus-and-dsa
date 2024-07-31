#include<stdio.h>
#define SQ(x) (x*x)
#define CUB(x) (SQ(x)*x)
#define POW(x) (CUB(x)/SQ(x))

int main(){
    float p = POW(2);
    printf("%f", p);
}