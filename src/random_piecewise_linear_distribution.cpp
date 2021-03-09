#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::vector<float> intervals{ 0, 10, 20, 30, 40};
    std::vector<float> densities{10,  2,  4,  4, 10};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::piecewise_linear_distribution<float> dist(intervals.begin(), intervals.end(), densities.begin());
    std::array<unsigned int, 40> counts{0};

    for (int i = 0; i < 100000; ++i)
        ++counts[static_cast<std::size_t>(dist(gen))];

    unsigned int m = *std::max_element(counts.begin(), counts.end());

    for (std::size_t i = 0; i != counts.size(); ++i) {
        std::cout << std::setw(2) << i << ": "
                  << std::setw(4) << counts[i] << " "
                  << std::string((40 * counts[i]) / m, '*') << '\n';
    }
}
