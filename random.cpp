#include <random>
#include <iostream>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 6);

    for (int i = 0; i < 100; ++i)
        std::cout << dist(gen) << " ";

    std::cout << std::endl;
}
