#include<stdio.h>
void setbit(int *x,int pos){
    *x = ((1<<pos)|(*x));

}
void clearbit(int *x, int pos){
    *x = (~(1<<pos)&(*x));
}


int main(int argc, char const *argv[])
{
     int x;
    printf("enter: ");
    scanf("%i",&x);
    for(int i=31; i>0; i=i-2){
     int mask1 = ((1<<i)&x)>>i;
    int mask2 = ((1<<(i-1))&x)>>(i-1);
    printf("%d %d\n",mask1,mask2);
    if(mask1==0&&mask2==1){
        setbit(&x,i);
        clearbit(&x,i-1);
    }
    else if((mask1==1||mask1==-1)&&mask2==0){
        setbit(&x,i-1);
        clearbit(&x,i);
    }

    }
    printf("%i",x);
    return 0;
}
