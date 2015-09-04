/*************************************************************************
 *  --------->    FILE: copy_construstor.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/04/2015    TIME:08:19:59
 ************************************************************************/

#include <iostream>
using namespace std;
class Point {
public:
    Point(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }
    Point(Point & p);

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

private:
    int x, y;
};

Point::Point(Point &p) {
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}

void fun1(Point p) {
    cout << p.getX() << endl;
}

Point fun2() {
    Point a(1, 2);
    return a;
}


int main() {
    Point a(4, 5);
    Point b = a;

    cout << b.getX() << endl;

    fun1(b);

    b = fun2();

    cout << b.getX() << endl;
    return 0;
}
