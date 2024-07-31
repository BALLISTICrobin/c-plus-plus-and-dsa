#include<stdio.h>
void remov(int a[],int size, int v){
    int *ptr = &a[size-1];
    while(*ptr!=v){
        ptr--;
    }
    while(ptr<&a[size-1]){
        *ptr = *(ptr+1);
        ptr++;
    }
    *ptr = 0;
    for(int i=0; i<size; i++){
        printf("%d ",a[i]);
    }
}

int main(int argc, char const *argv[])
{
    int num;
    printf("enter number of elements: ");
    scanf("%d",&num);
    int arr[num];
    for(int i=0; i<num; i++){
        scanf("%d",&arr[i]);
    }
    int v;
    printf("enter the element u want to remove: ");
    scanf("%d",&v);
    remov(arr,num,v);
    return 0;
}
