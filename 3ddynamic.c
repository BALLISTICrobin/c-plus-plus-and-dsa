#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int ***arr = (int***) malloc(1*sizeof(int**));
    for(int i=0; i<1; i++){
        arr[i] = (int**) malloc(2*sizeof(int*));
    }
    for(int i=0; i<1; i++){
        for(int j=0; j<2; j++){
            arr[i][j] = (int*)malloc(3*sizeof(int));
        }
    }
    printf("enter: ");
    for(int i=0; i<1; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<3; k++){
                scanf("%d",&arr[i][j][k]); 
            }
        }
    }
    for(int i=0; i<1; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<3; k++){
                printf("%d ",arr[i][j][k]); 
            }
        }
    }
    printf("%d %d",***arr,*(*(*arr+1)+2));
    return 0;
}
