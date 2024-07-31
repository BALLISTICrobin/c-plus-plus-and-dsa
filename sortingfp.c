#include<stdio.h>
#include<stdlib.h>
int comp(int a, int b){
    if(a>b)
    return 1;
    else
    return -1;
}
void bubbleSort(int *arr, int (*ptr)(int, int)){
    for(int i=0; i<6; i++){
        for(int j=0; j<6-i; j++){
            if(ptr(arr[j],arr[j+1])>0){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<6; i++){
        printf("%d ",arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int *arr = (int*)malloc(6*sizeof(int));
    for(int i=0; i<6; i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,comp);
    free(arr);
    return 0;
}
