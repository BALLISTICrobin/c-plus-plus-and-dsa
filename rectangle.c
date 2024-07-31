#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct point {
    int x,y;
}point;
int area(point *point1,point *point2,point *point3){
  return abs((point1->x*(point2->y-point3->y)-point2->x*(point1->y-point3->y)+point3->x*(point1->y-point2->y)));
}

int main(int argc, char const *argv[])
{
    point point1,point2,point3,point4,ch_point;
    printf("enter point1: ");
    scanf("%d %d",&point1.x,&point1.y);
    printf("enter point3: ");
    scanf("%d %d",&point3.x,&point3.y);
    point2.x = point1.x/1;
    point2.y = point3.y/1;
    point4.x = point3.x/1;
    point4.y = point1.y/1;
    float rec_area = (point3.x-point1.x)*(point1.y-point3.y);
    printf("enter the point u want to check: ");
    scanf("%d %d",&ch_point.x,&ch_point.y);
    float area1=0.5*(float)area(&ch_point,&point1,&point2);
    float area2=0.5*(float)area(&ch_point,&point2,&point3);
    float area3=0.5*(float)area(&ch_point,&point3,&point4);
    float area4=0.5*(float)area(&ch_point,&point4,&point1);
    float total_area = area1+area2+area3+area4;
    if(area1==0||area2==0||area3==0||area4==0)
    printf("on the rectangle");
    else if(rec_area==total_area)
    printf("inside the rectangle");
    else
    printf("outside the rectangle");

    return 0;
}
