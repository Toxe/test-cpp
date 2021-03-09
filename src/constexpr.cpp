#include <iostream>

int main()
{
    constexpr int a = 10;
    const int *p1 = &a;
  //constexpr int *p2 = &a;  // Fehler

    return 0;
}
