#include<iostream>
#include<cmath>
#include<stdbool.h>
using namespace std;

class Circle{
    int centerX,centerY;
    float radius;

    public:
    Circle(){

    }
    ~Circle(){}
    void setCenter(int a, int b){
        centerX = a;
        centerY = b;

    }
    void setRadius(float value){
        radius = value;
    }

    int getCenterX(){
        return centerX;
    }
    int getCenterY(){
        return centerY;
    }
    float getRadius(){
        return radius;
    }
    

}c;

class Quadrilateral{
    int vertexX[4];
    int vertexY[4];

    public:
    Quadrilateral(){}
    ~Quadrilateral(){}

    void setVertexX(int *arr){
        for(int i=0; i<4; i++){
            vertexX[i] = arr[i];
        }
    }
    void setVertexY(int *arr){
        for(int i=0; i<4; i++){
            vertexY[i] = arr[i];
        }
    }
    friend bool is_inscribed(Quadrilateral q);

}Q;

float distance(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool is_inscribed(Quadrilateral q){
    for(int i=0; i<4; i++){
        if(distance(q.vertexX[i],q.vertexY[i],c.getCenterX(),c.getCenterY())!=c.getRadius())
        return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    int centerx,centery;
    float center_radi;
    int arr1[4],arr2[4];
    cin>>centerx>>centery>>center_radi;
    c.setCenter(centerx,centery);
    c.setRadius(center_radi);
    for(int i=0;i<4;i++){
        cin>>arr1[i]>>arr2[i];
    
    }
    Q.setVertexX(arr1);
    Q.setVertexY(arr2);

    if(is_inscribed(Q))
    cout<<"inscribed"<<endl;
    else
    cout<<"not inscribed"<<endl;
    return 0;
}
