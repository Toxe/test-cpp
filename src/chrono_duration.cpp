#include <chrono>
#include <iostream>

using namespace std::literals::chrono_literals;

void output_seconds(const std::chrono::seconds s)
{
    std::cout << s.count() << "s\n";
}

void output_milliseconds(const std::chrono::milliseconds ms)
{
    std::cout << ms.count() << "ms\n";
}

void initialization()
{
    int ten = 10;

    // std::chrono::seconds s1 = 10;  // error: not implicitly constructible from int
    std::chrono::seconds s2{ten};
    std::chrono::seconds s3{10};
    std::chrono::seconds s4 = 10s;
    std::chrono::seconds s5 = s2 + s3 + s4;

    output_seconds(s5);
}

void conversion()
{
    // output_seconds(1);  // error: not implicitly constructible from int
    output_seconds(std::chrono::seconds{2});
    output_seconds(3s);

    output_milliseconds(std::chrono::seconds{2});
    output_milliseconds(3s);
}

void mixed_mode()
{
    std::chrono::seconds s{3};
    std::chrono::milliseconds ms{50};

    auto sum = s + ms;

    output_milliseconds(sum);
}

int main()
{
    initialization();
    conversion();
    mixed_mode();
}
