#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std::literals::chrono_literals;

void output_tp_seconds(const std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp)
{
    const std::time_t tc = std::chrono::system_clock::to_time_t(tp);
    std::cout << tp.time_since_epoch().count() << "s = " << std::put_time(std::localtime(&tc), "%F %T") << '\n';
}

void cast()
{
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp_seconds{8000s};
    // const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp_hours = tp_seconds;  // error: no loss-less conversion possible
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp_hours = std::chrono::time_point_cast<std::chrono::hours>(tp_seconds);

    output_tp_seconds(tp_seconds);
    output_tp_seconds(tp_hours);
}

int main()
{
    cast();
}
