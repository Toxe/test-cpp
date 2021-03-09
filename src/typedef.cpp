#include <iostream>

typedef int foo;

int main()
{
    foo a = 1;
    const foo *p = &a;
  //*p = 2;  // Fehler

    return 0;
}
