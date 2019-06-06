#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

    auto print = [](int i) { std::cout << i << "\n"; };
    print(-42);
    std::for_each(v.begin(), v.end(), print);

    int big = 5;
    auto count1 = std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
    auto count2 = std::count_if(v.begin(), v.end(), [=](int i) { return i > big; });

    std::cout << count1 << " " << count2 << std::endl;
    return 0;
}
