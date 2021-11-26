#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
using auto_delete_resource = std::unique_ptr<T, void (*)(T*)>;

struct Thing {
    Thing(const char* thing_name) : name{thing_name}
    {
        std::cout << "[" << this << "] " << name << ": created\n";
    }

    ~Thing()
    {
        std::cout << "[" << this << "] " << name << ": destroyed\n";
    }

    void use()
    {
        std::cout << "[" << this << "] " << name << ": using\n";
    }

    const char* name;
};

Thing* alloc(const char* name)
{
    return new Thing(name);
}

void free(Thing* thing)
{
    if (thing)
        delete thing;
}

void test_normal()
{
    Thing* thing = alloc("thing");
    thing->use();
    free(thing);
}

void test_auto1()
{
    auto_delete_resource<Thing> thing = auto_delete_resource<Thing>(alloc("auto 1"), [](Thing* t) { free(t); });
    thing->use();
}

void test_auto2()
{
    auto_delete_resource<Thing> thing = {nullptr, nullptr};
    thing = auto_delete_resource<Thing>(alloc("auto 2"), [](Thing* t) { free(t); });
    thing->use();
}

void test_exception()
{
    try {
        auto_delete_resource<Thing> thing = auto_delete_resource<Thing>(alloc("exception"), [](Thing* t) { free(t); });
        thing->use();
        throw std::runtime_error("oh no, something happened with \"exception\" thing");
        thing->use();
    } catch (const std::runtime_error& e) {
        std::cout << "caught exception: " << e.what() << '\n';
    }
}

int main()
{
    test_normal();
    test_auto1();
    test_auto2();
    test_exception();
}
