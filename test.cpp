#include<iostream>
using namespace std;

class enemy{
    private:
    int a,b,c;

    public:
    int d,e;
    void setData(int a1,int b1, int c1 );
    void getData(){
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;
        cout<<d<<endl;
        cout<<e<<endl;
    }
}en;
void enemy :: setData(int a1, int b1, int c1){
    a=a1;
    b=b1;
    c=c1;
} 

int main(int argc, char const *argv[])
{
    en.d=4;
    en.e=5;
    en.setData(1,2,3);
    en.getData();
    
    return 0;
}
