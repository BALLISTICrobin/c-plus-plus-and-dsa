#include<iostream>
using namespace std;
class rectangle{
    int *width,*length;
    public:
    rectangle(){
        width =new int;
        length =new int;
    }
    rectangle(int a,int b){
        width =new int;
        length =new int;
        *width = a;
        *length = b;

    }

    //copy constructor
    rectangle(const rectangle &original){
        width = new int;
        length = new int;
        *width = *(original.width);
        *length = *(original.length);
    }
    ~rectangle(){
        delete width;
        delete length;
    }
    int area(){
        return (*width)*(*length);
    }
};

rectangle larger(rectangle rectX, rectangle rectY) {
    if (rectX.area() > rectY.area())
        return rectX;
    else
        return rectY;
}

int main(int argc, char const *argv[])
{
    rectangle rectA(10,20),rectB(5,30);
   rectangle rect_temp = larger(rectA, rectB);
    cout << rect_temp.area() << endl;
    return 0;
}
