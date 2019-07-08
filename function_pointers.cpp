#include <iostream>
#include <string>

std::string::size_type calc_length(const std::string &s1, const std::string &s2)
{
    return s1.size() + s2.size();
}


int main()
{
    std::string::size_type(*p1) (const std::string &, const std::string &);
    p1 = calc_length;

    decltype(calc_length) *p2 = calc_length;

    std::cout << p1("hello", "world") << std::endl;
    std::cout << p2("hello", "world") << std::endl;

    return 0;
}
