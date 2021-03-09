#include <iostream>
#include <memory>
#include <new>
#include <string>

static size_t count_alloc = 0;
static size_t count_dealloc = 0;
static size_t sum_alloc_size = 0;

template <typename T>
struct MyAllocator {
    using value_type = T;

    MyAllocator() = default;

    template <typename U>
    MyAllocator(const MyAllocator<U>&) noexcept {}

    T* allocate(size_t n) {
        std::cout << "allocate " << (sizeof(T) * n) << " bytes\n";
        ++count_alloc;
        sum_alloc_size += sizeof(T) * n;
        auto p = operator new(sizeof(T) * n);
        return static_cast<T*>(p);
    }

    void deallocate(T* p, size_t n) {
        std::cout << "deallocate " << (sizeof(T) * n) << " bytes\n";
        ++count_dealloc;
        operator delete(p);
    }
};

template <typename T1, typename T2>
bool operator==(const MyAllocator<T1>&, const MyAllocator<T2>&) noexcept {
    return true;
}

template <typename T1, typename T2>
bool operator!=(const MyAllocator<T1>&, const MyAllocator<T2>&) noexcept {
    return false;
}

struct Foo {
    Foo(std::string s) : name{s} { std::cout << "Creating \"" << name << "\"\n"; };
    ~Foo() { std::cout << "Destroying \"" << name << "\"\n"; };
    std::string name;
};

void do_something(const Foo& foo)
{
    std::cout << "Using \"" << foo.name << "\"\n";
}

using MyAllocString = std::basic_string<char, std::char_traits<char>, MyAllocator<char>>;

int main()
{
    std::allocator<Foo> a;
    auto foos = a.allocate(3);

    a.construct(foos,     "Test 1");
    a.construct(foos + 1, "Test 2");
    a.construct(foos + 2, "Test 3");

    for (int i = 0; i < 3; i++)
        do_something(foos[i]);

    for (int i = 0; i < 3; i++)
        a.destroy(&foos[i]);

    a.deallocate(foos, 3);

    std::cout << "-------------------------------------\n";

    {
        MyAllocator<Foo> foo_alloc;
        auto f = std::allocate_shared<Foo>(foo_alloc, "MyAllocator<Foo> Test");
    }

    std::cout << "-------------------------------------\n";

    {
        auto s1 = new MyAllocString{"string with long text to prevent short string optimization"};
        std::cout << "created MyAllocString \"" << *s1 << "\"\n";
        delete s1;

        MyAllocString s2{"another long string to prevent SSO"};
        std::cout << "created MyAllocString \"" << s2 << "\"\n";

        MyAllocString s3{"shorty"};
        std::cout << "created MyAllocString \"" << s3 << "\"\n";
    }

    std::cout << "-------------------------------------\n";

    std::cout << "--> allocated: " << count_alloc << " times for " << sum_alloc_size << " bytes\n";
    std::cout << "--> deallocated: " << count_alloc << " times\n";
}
