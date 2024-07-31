#include<stdio.h>
#include<stdlib.h>
#define nrows 3
#define ncols 3
int** allocate(void){
    int** a = (int **) malloc(nrows*sizeof(int*));
    for(int i=0; i<3; i++){
        a[i] = (int*) malloc(ncols*sizeof(int));
    }
    printf("enter: ");
    for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            scanf("%d",(*(a+i)+j));
        }
    }
   
    for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            printf("%d ",*(*(a+i)+j));
            if(j==ncols-1)
            printf("\n");
        }
    }
    return a;
}

int **addition(int **a, int **b){
    int** c = (int **) malloc(nrows*sizeof(int*));
    for(int i=0; i<3; i++){
        c[i] = (int*) malloc(ncols*sizeof(int));
    }
    for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            *(*(c+i)+j) = *(*(a+i)+j) + *(*(b+i)+j);
        }
    }
    return c;
}



int main(){
    int **a = allocate();
    int **b = allocate();
    int **c = addition(a,b);
    for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            
        }
    }
   for(int i=0; i<nrows; i++){
        for(int j=0; j<ncols; j++){
            printf("%d ",*(*(c+i)+j));
            if(j==ncols-1)
            printf("\n");
        }
    }
    free(a);
    return 0;
}