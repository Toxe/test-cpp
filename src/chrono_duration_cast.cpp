#include <chrono>
#include <iostream>

using namespace std::literals::chrono_literals;

void output_seconds(const std::chrono::seconds s)
{
    std::cout << s.count() << "s\n";
}

void conversion()
{
    // std::chrono::seconds s1{5000ms};  // error: no loss-less conversion possible
    // std::chrono::seconds s2{5100ms};  // error: no loss-less conversion possible
    // std::chrono::seconds s3{4900ms};  // error: no loss-less conversion possible
    std::chrono::seconds s4 = std::chrono::duration_cast<std::chrono::seconds>(5000ms);
    std::chrono::seconds s5 = std::chrono::duration_cast<std::chrono::seconds>(5100ms);
    std::chrono::seconds s6 = std::chrono::duration_cast<std::chrono::seconds>(4900ms);

    output_seconds(s4);
    output_seconds(s5);
    output_seconds(s6);
}

void truncation()
{
    output_seconds(std::chrono::duration_cast<std::chrono::seconds>(4900ms));  // 4s
    output_seconds(std::chrono::floor<std::chrono::seconds>(4900ms));  // 4s
    output_seconds(std::chrono::round<std::chrono::seconds>(4900ms));  // 5s
    output_seconds(std::chrono::ceil<std::chrono::seconds>(4900ms));  // 5s
}

int main()
{
    conversion();
    truncation();
}
