#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;


int main()
{
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

    auto is_bigger = [](int i, int num) {return i > num; };

    for (int big = 1; big <= 10; ++big) {
        auto c = std::count_if(v.begin(), v.end(), std::bind(is_bigger, _1, big));
        std::cout << "[" << big << "] " << c << std::endl;
    }

    return 0;
}
