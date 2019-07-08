#include <iostream>

class NumImplicit {
public:
    NumImplicit(int num) : num_{num} {};
    void print() { std::cout << "NumImplicit: " << num_ << std::endl; };
private:
    int num_;
};

class NumExplicit {
public:
    explicit NumExplicit(int num) : num_{num} {};
    void print() { std::cout << "NumExplicit: " << num_ << std::endl; };
private:
    int num_;
};

void print_implicit(NumImplicit im) { im.print(); }
void print_explicit(NumExplicit ex) { ex.print(); }

int main()
{
    NumImplicit i1(1);
    NumImplicit i2{2};
    NumImplicit i3 = 3;

    NumExplicit e1(1);
    NumExplicit e2{2};
    // NumExplicit e3 = 3;  // Fehler

    print_implicit(NumImplicit{4});
    print_explicit(NumExplicit{4});
    print_implicit(5);
    // print_explicit(5);  // Fehler
}
