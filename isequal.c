#include<stdio.h>
int isequal(int x,int y){
    return x^y;

}

int main(int argc, char const *argv[])
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",isequal(x,y));
    return 0;
}
