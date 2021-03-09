#include <iostream>

struct Foo {
    Foo(int n) : value{n}
    {
        std::cout << "constructed " << this << " with value = " << value << std::endl;
    }

    Foo(const Foo& other) : value{other.value}
    {
        std::cout << "constructed " << this << " with value = " << value << ", copied from: " << &other << std::endl;
    }

    Foo& operator=(const Foo& other)
    {
        if (&other == this)
            return *this;

        std::cout << "copy value = " << other.value << " from " << &other << " to " << this << std::endl;

        value = other.value;
        return *this;
    }

    int value;
};

int main()
{
    Foo a{10};
    Foo b{0};
    Foo c = a;  // copy constructor
    b = a;

    std::cout << "a = " << a.value << std::endl;
    std::cout << "b = " << b.value << std::endl;
    std::cout << "c = " << c.value << std::endl;
}
