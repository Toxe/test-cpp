#include <array>
#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<int> dist({5, 1, 1, 3}); // 0=50%, 1=10%, 2=10%, 3=30%
    std::array<int, 4> counts{0};

    for (int i = 0; i < 100000; ++i)
        ++counts[static_cast<std::size_t>(dist(gen))];

    for (std::size_t i = 0; i != counts.size(); ++i)
        std::cout << i << ": " << counts[i] << " times\n";
}
