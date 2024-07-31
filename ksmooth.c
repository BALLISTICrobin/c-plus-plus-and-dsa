#include<stdio.h>
#include<math.h>
int kSmooth(int num, int k){
    int count=0;
  for(int i=k+1;i<num/2; i++){
    if(num%i==0){
        int count2=0;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==0)
        return 0;
    }
  }
  return 1;

}

int main(int argc, char const *argv[])
{
    int x,k;
    scanf("%d %d",&x,&k);
    printf("%d",kSmooth(x,k));

    return 0;
}
