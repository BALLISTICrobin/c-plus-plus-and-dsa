#include<stdio.h>

void idtocode(int x){

int serial = x%1000;
int dept = (serial/1000)%100;
int year = (serial/1000)/100;
int nyear = year | 2000;
int stcode = nyear<<(9+9-2)|(dept<<8)|serial;
printf("%i",stcode);

}



int main(int argc, char const *argv[])
{
    unsigned int id;
    scanf("%i",&id);
    idtocode(id);
    return 0;
}
