#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in{"../primes_column_separated.txt"};
    std::ofstream out{"../primes.txt"};
    std::string s;

    while (in >> s)
        out << s << "\n";
}
