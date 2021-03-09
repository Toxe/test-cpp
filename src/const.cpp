#include <iostream>

int main()
{
    const int a = 10;
  //int &r1 = a;  // Fehler

    int b = 20;
    const int &r2 = b;
  //r2 = 30;  // Fehler
    b = 30;

    const int *p1 = &b;
    int *const p2 = &b;
  //*p1 = 40;  // Fehler
    *p2 = 40;

    std::cout << a << " " << r2 << " " << *p1 << " " << *p2 << std::endl;

    return 0;
}
