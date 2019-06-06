#include <iostream>

typedef int foo;

float test()
{
    return 1.0f;
}

int main()
{
    decltype(foo()) a = 1;
    decltype(test()) f = 2.0;
    decltype(a) b = 3;

    return 0;
}
