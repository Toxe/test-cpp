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


void do_something(std::unique_ptr<Foo> &foo)
{
    std::cout << "Using \"" << foo->name << "\".\n";
}

void simple1()
{
    std::unique_ptr<Foo> foo(new Foo("Simple Test 1"));
    do_something(foo);
}

void simple2()
{
    auto foo = std::make_unique<Foo>("Simple Test 2");  // C++14
    do_something(foo);
}

void reset()
{
    auto foo = std::make_unique<Foo>("Reset 1");
    do_something(foo);
    foo.reset(new Foo("Reset 2"));
    do_something(foo);
    foo.reset(new Foo("Reset 3"));
    do_something(foo);
}

std::unique_ptr<Foo> factory1()
{
    std::unique_ptr<Foo> foo(new Foo("Factory Test 1"));

    return foo;
}

std::unique_ptr<Foo> factory2()
{
    return std::unique_ptr<Foo>(new Foo("Factory Test 2"));
}

int main()
{
    simple1();
    std::cout << "--------------------------\n";

    simple2();
    std::cout << "--------------------------\n";

    reset();
    std::cout << "--------------------------\n";

    auto foo1 = factory1();
    auto foo2 = factory2();
    do_something(foo1);
    do_something(foo2);

    return 0;
}
