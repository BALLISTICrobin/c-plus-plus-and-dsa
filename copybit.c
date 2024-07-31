#include<stdio.h>
int copyAbit(int x,int y,int n){
int mask = ~((y & (1<<n))>>n)+1;
return mask;
}
int reversebits(int y){
    int x = 0;
    for(int i=0;i<sizeof(int); i++){
       x = x|(((1<<i)&y)<<(31-i));
    }
    return x;
}
int main(int argc, char const *argv[])
{
    int x,y,n;   
    scanf("%d %d %d",&x,&y,&n);
    //printf("%d\n",copyAbit(x,y,n));
    printf("%d ",reversebits(y));

    return 0;
}
