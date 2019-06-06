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


void simple()
{
    auto test1 = std::make_shared<Foo>("Simple Test 1");
    auto test2 = std::make_shared<Foo>("Simple Test 2");
    auto test3 = std::make_shared<Foo>("Simple Test 3");

    test2 = test1;
}

std::shared_ptr<Foo> factory()
{
    auto test3 = std::make_shared<Foo>("Factory Test");

    std::cout << "use count: " << test3.use_count() << "\n";

    return test3;
}

void do_something(std::shared_ptr<Foo> foo)
{
    std::cout << "[do_something] use count: " << foo.use_count() << "\n";
}

void do_something_better(std::shared_ptr<Foo> &foo)
{
    std::cout << "[do_something_better] use count: " << foo.use_count() << "\n";
}

int main()
{
    simple();

    auto test3 = factory();
    std::cout << "use count: " << test3.use_count() << "\n";
    do_something(test3);
    do_something_better(test3);

    return 0;
}
