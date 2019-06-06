#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    std::vector<int> v2{1, 2, 3};

    return 0;
}
