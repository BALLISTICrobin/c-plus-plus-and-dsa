#include <iostream>
using namespace std;

class Vector
{
    double x, y, z;
    string name;

public:
    Vector(double x = 0, double y = 0, double z = 0, string name = "")
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->name = name;
    }

    Vector operator+(Vector &v){
        Vector temp;
        temp.x = x + v.x;
        temp.y = y + v.y;
        temp.z = z + v.z;
        temp.name = name + v.name;
        return temp;
    }
    Vector operator+=(Vector &v){
        x += v.x;
        y += v.y;
        z += v.z;
        name += v.name;
        return *this;
    }
    Vector operator +(double val){
        Vector temp;
        temp.x = x + val;
        temp.y = y + val;
        temp.z = z + val;
        temp.name = name;
        return temp;
    }
    friend Vector operator+(double val, Vector &v){
        Vector temp;
        temp.x = val + v.x;
        temp.y = val + v.y;
        temp.z = val + v.z;
        temp.name = v.name;
        return temp;
    }
    void show(){
        cout << name << ": " << x << ", " << y << ", " << z << endl;
    }
};

int main(int argc, char const *argv[])
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6, "v2");
    v1.show();
    v2.show();
    Vector v3 ;
    v3= v1 + v2;
    v3.show();
    v1 = v2+=v3;
    v1.show();
    v2.show();
    v2 = v2 +100.9;
    v2.show();
    v2 = 100.9 + v2;
    v2.show();

    return 0;
}
