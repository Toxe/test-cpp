#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

void output_tp_seconds(const std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp)
{
    const std::time_t tc = std::chrono::system_clock::to_time_t(tp);
    std::cout << std::put_time(std::localtime(&tc), "%F %T") << '\n';
}

void output_duration_seconds(const std::chrono::seconds dur)
{
    std::cout << dur << '\n';
}

void output_duration_nanoseconds(const std::chrono::nanoseconds dur)
{
    std::cout << dur << '\n';
}

void current_time()
{
    const auto tp1 = std::chrono::system_clock::now();
    const auto tp2 = std::chrono::steady_clock::now();

    output_tp_seconds(std::chrono::time_point_cast<std::chrono::seconds>(tp1));
    output_duration_seconds(std::chrono::duration_cast<std::chrono::seconds>(tp2.time_since_epoch()));
}

void measure_time()
{
    const auto tp1 = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(1ms);
    const auto tp2 = std::chrono::steady_clock::now();

    output_duration_nanoseconds(tp2 - tp1);
}

int main()
{
    current_time();
    measure_time();
}
