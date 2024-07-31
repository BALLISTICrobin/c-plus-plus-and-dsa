#include<iostream>
using namespace std;

class Complex
{
private:
    double real, im;
    int arr[10];
public:
    Complex(){
        real =0;
        im = 0;
        for(int i=0;i<10;i++)
            arr[i] = i;
    }
    Complex(double a, double b){
        real = a;
        im = b;
    }
    void display(){
        cout<<real<<" + "<<"i"<<im<<endl;
    }

    Complex operator+(Complex &comp){
        Complex temp;
        temp.real = real + comp.real;
        temp.im = im + comp.im;
        return temp;
    }

    void operator+=(int value){
        real+=value;
        im += value;
    }

    void operator -=(int value){
        real-=value;
        im -= value;
    }

    void operator ++(){
        real++;
        im++;
    }

    int& operator[](int index){
        if(index<0 || index>=10){
            cout<<"index out of bound"<<endl;
            exit(1);
        }
        return arr[index];
    }

    Complex operator ++(int){
        cout<<"hi"<<endl;
        Complex temp = *this;
        
        real++;
        im++;
        return temp;
    }

    friend ostream& operator<<(ostream &COUT,Complex &comp);
    friend istream& operator>>(istream &CIN,Complex &comp);
    
    
};
ostream& operator<<(ostream &COUT,Complex &comp){
        COUT<<comp.real<<" + "<<"i "<<comp.im<<endl;
        return COUT;
    }
istream& operator>>(istream &CIN,Complex &comp){
        CIN>>comp.real>>comp.im;
        return CIN;
    }


int main(int argc, char const *argv[])
{
    Complex c1(3.5,6.7778),c2(3.9994,2.3394);
    Complex c3 = c1+c2;
    cout<<c3;
    c3+=10;
    cout<<c3;
    c3-=4;
    cout<<c3;
    ++c3;
    cout<<c3;
    (c3++).display();
    c3 = c3++;
    cout<<c3;
    Complex c4 = c3++;
    cout<<c4;
    Complex c5; 
    cout<<"enter new complex number:";
    cin>>c5;
    cout<<c5;
    for(int i=0; i<10; i++){
        c5[i] = i+2;
    }
    for(int i=0; i<10; i++){
        cout<<c5[i]<<" ";
    }
    Complex c6;
    c6=c5=c4;
    cout<<c6;
    return 0;
}
