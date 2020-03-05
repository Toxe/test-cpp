#include <iostream>
#include <vector>

int main()
{
    // initialization with 0
    int a = 0;
    int b = {};
    int c{};

    // initialization with value
    int d = 10;
    int e = {10};
    int f{10};
    int g(10);

    // short i1{1.0};      // error
    // short i2{100'000};  // error

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2{4, 5, 6};
}
