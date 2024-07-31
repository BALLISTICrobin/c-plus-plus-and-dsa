#include <iostream>
#include <cmath>
#include <stdbool.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point()
    {
    }
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    ~Point() {}
    void setX(int value)
    {
        x = value;
    }

    void setY(int value)
    {
        y = value;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    Point operator+(Point p)
    {
        Point temp;
        temp.setX(x + p.getX());
        temp.setY(y + p.getY());
        return temp;
    }

    bool operator==(Point p)
    {
        return (x == p.getX()) && (y == p.getY());
    }

    Point operator/(int d)
    {
        Point temp;
        temp.setX(x / d);
        temp.setY(y / d);
        return temp;
    }
};

class Circle
{
    Point center;
    int radius;

public:
    Circle() {}
    ~Circle() {}
    void setCenter(int center_x, int center_y)
    {
        center.setX(center_x);
        center.setY(center_y);
    }

    void setRadius(int value)
    {
        radius = value;
    }
    Point getCenter()
    {
        return center;
    }
    int getRadius()
    {
        return radius;
    }
};

class Rectangle
{
    Point *vertex;

public:
    Rectangle()
    {
        vertex = new Point[5];
    }
    ~Rectangle()
    {
        delete[] vertex;
    }
    Rectangle(const Rectangle &original)
    {
        vertex = new Point[4];
        for (int i = 0; i < 4; i++)
        {
            vertex[i] = original.vertex[i];
        }
    }

    void setVertex(Point *arr)
    {
        for (int i = 0; i < 4; i++)
        {
            vertex[i] = arr[i];
        }
    }

    friend bool issquare(Rectangle rec);
    friend bool is_inscribed(Circle, Rectangle);
};
int distance(Point p1, Point p2)
{
    return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
}
bool issquare(Rectangle rec)
{
    float comp = distance(rec.vertex[0], rec.vertex[1]);
    for (int i = 1; i < 3; i++)
    {
        if (comp != distance(rec.vertex[i], rec.vertex[i + 1]))
            return false;
    }
    if (comp != distance(rec.vertex[3], rec.vertex[0]))
        return false;

    return true;
}

bool is_inscribed(Circle C, Rectangle R)
{
    int count = 0;
    if (!issquare(R))
    {
        return false;
    }
    else
    {
        if (distance(R.vertex[0], R.vertex[1]) == 2 * C.getRadius())
            count++;
        else
            return false;
    }

    if ((R.vertex[0] + R.vertex[2]) / 2 == C.getCenter() && (R.vertex[1] + R.vertex[3]) / 2 == C.getCenter())
        count++;
    else
        return false;

    if (count == 2)
        return true;

    return 1;
}

int main(int argc, char const *argv[])
{
    int cenX, cenY, radi;
    Point coordinate[4];
    cin >> cenX >> cenY >> radi;

    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        coordinate[i].setX(x);
        coordinate[i].setY(y);
    }
    Circle cir;
    cir.setCenter(cenX, cenY);
    cir.setRadius(radi);

    Rectangle Rect;
    Rect.setVertex(coordinate);

    if (is_inscribed(cir, Rect))
        cout << "inscribed" << endl;
    else
        cout << "not inscribed" << endl;

    return 0;
}
