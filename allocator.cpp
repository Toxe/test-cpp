#include <iostream>
#include <string>
#include <memory>

class Foo {
public:
    Foo(std::string s) : name(s) { std::cout << "Created \"" << name << "\".\n"; };
    ~Foo() { std::cout << "Destroyed \"" << name << "\".\n"; };

public:
    std::string name;
};


void do_something(const Foo *foo)
{
    std::cout << "Using \"" << foo->name << "\".\n";
}

int main()
{
    std::allocator<Foo> a;
    auto foos = a.allocate(3);

    a.construct(foos,     "Test 1");
    a.construct(foos + 1, "Test 2");
    a.construct(foos + 2, "Test 3");

    for (int i = 0; i < 3; i++)
        do_something(&foos[i]);

    for (int i = 0; i < 3; i++)
        a.destroy(&foos[i]);

    a.deallocate(foos, 3);

    return 0;
}
