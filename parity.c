#include<stdio.h>
void checkParity(int n){
int mask = n^1;
if(mask==0){
    printf("even\n");
}
else
printf("odd\n");
}
int main(){
    int n;
    scanf("%d",&n);
    checkParity(n);
    return 0;
}