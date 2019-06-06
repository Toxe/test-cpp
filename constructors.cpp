#include <iostream>

struct Point {
    int x = 0;
    int y = 0;

    Point() = default;
    Point(int defaultX, int defaultY) : x(defaultX), y(defaultY) { };

    void print() { std::cout << "{" << x << "," << y << "}" << std::endl; };
};


int main()
{
    Point p1;
    Point p2(1, 2);
    Point p3{ 3, 4 };
    Point p4 = { 5, 6 };
    Point p5 = p4;
    Point p6(p5);

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    p6.print();

    return 0;
}
