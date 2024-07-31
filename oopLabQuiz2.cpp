#include <iostream>
using namespace std;

class Rectangle {
	int *width, *height;
public:
	Rectangle(int, int);
	~Rectangle ();
    Rectangle(const Rectangle &original){
		cout<<"copy constructor"<<endl;
        width = new int;
        height = new int;
        *width = *original.width;
        *height = *original.height;
    }
	int area () {return (*width * *height);}

    void operator=(Rectangle obj){
		cout<<"assignment operator"<<endl;
        *this->width = *obj.width;
        *this->height = *obj.height;
    }
};

Rectangle::Rectangle (int a, int b) {
	cout<<"constructor"<<endl;
	width= new int;
	height = new int;
	*width = a;
	*height = b;
}

Rectangle:: ~Rectangle () {
	cout<<"destructor"<<endl;
	delete width;
	delete height;
}

Rectangle larger(Rectangle recta, Rectangle rectb){
	if(recta.area()>rectb.area())
		return recta;
	else
		return rectb;
}
int main () {
	Rectangle recta (3,4);
	Rectangle rectb (5,6);
	Rectangle rect_larger(0,0);
	
	rect_larger=larger(recta, rectb); //this will cause the program to crash
	
	cout << "recta area: " << recta.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	cout << "rect_larger area: " << rect_larger.area() << endl;
	return 0;
} 
