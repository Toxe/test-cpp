#include <iostream>

struct Point {
    int x_ = 0;
    int y_ = 0;
    int z_ = 0;

    Point() = default;
    Point(int x, int y, int z) : x_(x), y_(y), z_{z} { };
    // Point(int x, int y, int z) : z_(z), y_(y), x_{x} { };  // Warnung, falsche Reihenfolge

    void print() { std::cout << "{" << x_ << "," << y_ << "," << z_ << "}" << std::endl; };
};


int main()
{
    Point p1;
    Point p2(1, 2, 3);
    Point p3{4, 5, 6};
    Point p4 = {7, 8, 9};
    Point p5 = p4;
    Point p6(p4);
    Point p7(p4);

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    p6.print();
    p7.print();
}
