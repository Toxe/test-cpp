#include <iostream>

int main()
{
    int big = 0x4241;  // "AB"
    char small = static_cast<char>(big);  // --> 'A'

    int i = 1;
    const int *ci = &i;
  //int *pi = ci;  // Fehler
    int *pi = const_cast<int *>(ci);
    *pi = 2;

  //char *pc = &big;  // Fehler
    char *pc = reinterpret_cast<char *>(&big);

    std::cout << small << " " << *pi << " " << *pc << std::endl;

    return 0;
}
