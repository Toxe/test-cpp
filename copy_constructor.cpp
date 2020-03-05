#include <iostream>

struct Foo {
    Foo(int n = 0) : value{n}
    {
        std::cout << "constructed " << this << " with value = " << value << std::endl;
    }

    Foo(const Foo& other) : value{other.value}
    {
        std::cout << "constructed " << this << " with value = " << value << ", copied from: " << &other << std::endl;
    }

    int value;
};

void func1(const Foo val)
{
    std::cout << "called func1 with value = " << val.value << ", Foo = " << &val << std::endl;
}

void func2(const Foo& ref)
{
    std::cout << "called func2 with value = " << ref.value << ", Foo = " << &ref << std::endl;
}

int main()
{
    Foo a{10};   // default constructor
    Foo b = 20;  // default constructor
    Foo c;       // default constructor
    Foo d{};     // default constructor
    Foo e();     // warning, defines a function e() that returns a Foo
    Foo f{a};    // copy constructor
    Foo g = b;   // copy constructor

    std::cout << "a = " << a.value << std::endl;
    std::cout << "b = " << b.value << std::endl;
    std::cout << "c = " << c.value << std::endl;
    std::cout << "d = " << d.value << std::endl;
  //std::cout << "e = " << e.value << std::endl;
    std::cout << "f = " << f.value << std::endl;
    std::cout << "g = " << g.value << std::endl;

    func1(a);  // calls copy constructor
    func2(a);
}
