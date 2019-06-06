#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    auto it1 = v1.begin();   // std::vector<int>::iterator
    auto it2 = v1.cbegin();  // std::vector<int>::const_iterator

    for (auto it = v1.begin(); it != v1.end(); ++it)
        std::cout << *it << std::endl;

    int a[] = {10, 11, 12};

    for (auto it = std::begin(a); it != std::end(a); ++it)
        std::cout << *it << std::endl;

    return 0;
}
