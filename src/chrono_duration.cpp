#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

int main()
{
    std::chrono::minutes minutes{2};
    std::chrono::seconds seconds{5};
    auto sum = minutes + seconds;
    std::cout << minutes.count() << "m + " << seconds.count() << "s = " << sum.count() << "s\n";

    seconds = 5min;  // automatic cast of minutes --> seconds
    // minutes = 300s;  // error, needs explicit duration_cast<>
    minutes = std::chrono::duration_cast<std::chrono::minutes>(301s);
    std::cout << minutes.count() << "m, " << seconds.count() << "s\n";

    auto t0 = std::chrono::high_resolution_clock::now();  // returns most likely nanoseconds
    std::this_thread::sleep_for(5ms);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);

    std::cout << "slept for " << us.count() << "μs or " << (t1 - t0).count() << " (probably) ns\n";
    std::cout << "std::chrono::high_resolution_clock period = "
              << std::chrono::high_resolution_clock::period::num << ":"
              << std::chrono::high_resolution_clock::period::den << '\n';
}
