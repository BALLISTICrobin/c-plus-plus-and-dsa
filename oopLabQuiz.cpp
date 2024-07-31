#include <iostream>
using namespace std;

class Rectangle {
    int *width, *height;

public:
    
    Rectangle(int, int);
    // Rectangle(const Rectangle &); // Copy constructor
    Rectangle& operator=(const Rectangle ); // Copy assignment operator
    ~Rectangle();
    //initialization
    //pass by value
    //return value
    Rectangle(const Rectangle& original){
        cout<<"copy constructor"<<endl;
        width = new int;
        height = new int;
        *width = *original.width;
        *height = *original.height;

    }
    int area() { return (*width * *height); }
};

Rectangle::Rectangle(int a, int b) {
    cout<<"constructor"<<endl;
    width = new int;
    height = new int;
    *width = a;
    *height = b;
}



// Copy assignment operator
//to avoid shallow copy
Rectangle& Rectangle::operator=(const Rectangle other) {
    *this->width = *other.width;
    *this->height = *other.height;
    return *this;
}

Rectangle::~Rectangle() {
    cout<<"destructor"<<endl;
    delete width;
    delete height;
}

int main() {
    Rectangle recta(3, 4), rectb(5, 6);
    recta = rectb;
    Rectangle rectc(recta);
    cout << "recta area: " << recta.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    cout<<"rectc area: "<<rectc.area()<<endl;
    return 0;
}
