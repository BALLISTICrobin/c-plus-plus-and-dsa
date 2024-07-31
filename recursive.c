#include<stdio.h>
#include<stdlib.h>
int find_largest_number(int arr[],int size){
    if(size==1)
    return arr[size-1];
int possible_max=find_largest_number(arr,size-1);
if(possible_max>=arr[size-1])
return possible_max;
else
return arr[size-1];
}
int main(int argc, char const *argv[])
{
    int n;
    printf("enter number of integers: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("enter: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",find_largest_number(arr,n));
    free(arr);
    return 0;
}
