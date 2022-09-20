#include <array>
#include <iostream>
#include <iterator>
#include <vector>

void simple_usage()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    auto it1 = v1.begin();  // std::vector<int>::iterator
    auto it2 = v1.cbegin();  // std::vector<int>::const_iterator

    for (auto it = v1.begin(); it != v1.end(); ++it)
        std::cout << *it << std::endl;

    int a[] = {10, 11, 12};

    for (auto it = std::begin(a); it != std::end(a); ++it)
        std::cout << *it << std::endl;
}

class Grid {
    class iterator {
    public:
        using iterator_category = std::input_iterator_tag;
        using value_type = int;
        using difference_type = int;
        using pointer = int*;
        using reference = int&;
    };

    std::array<int, 25> numbers_;

public:
    Grid()
    {
        for (int i = 0; i < numbers_.size(); ++i)
            numbers_[i] = i + 1;
    }

    void print()
    {
        for (const auto n : numbers_)
            std::cout << n << ' ';

        std::cout << '\n';
    }
};

void custom_iterator()
{
    Grid grid;
    grid.print();
}

int main()
{
    simple_usage();

    std::cout << "-----------------\n";

    custom_iterator();
}
