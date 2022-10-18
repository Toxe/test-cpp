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

void output_tp_hours(const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp)
{
    const std::time_t tc = std::chrono::system_clock::to_time_t(tp);
    std::cout << tp.time_since_epoch().count() << "h = " << std::put_time(std::localtime(&tc), "%F %T") << '\n';
}

void output_hours(const std::chrono::hours dur)
{
    std::cout << dur << '\n';
}

void conversion()
{
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp_seconds1{5000s};  // seconds
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp_seconds2{5000h};  // hours to seconds

    output_tp_seconds(tp_seconds1);  // 5000s = 1970-01-01 02:23:20
    output_tp_seconds(tp_seconds2);  // 18000000s = 1970-07-28 10:00:00

    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp_hours1{5000h};  // hours

    output_tp_seconds(tp_hours1);  // 18000000s = 1970-07-28 10:00:00
    output_tp_hours(tp_hours1);  // 5000h = 1970-07-28 10:00:00

    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp_hours2{};

    output_tp_hours(tp_hours2);  // 0h = 1970-01-01 01:00:00

    // const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp_hours2{3600s};  // error: no loss-less conversion possible
}

void arithmetic()
{
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp1{5000h};
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp2{6000h};

    // subtraction: time_point - time_point --> duration (std::chrono::hours)
    output_hours(tp2 - tp1);  // 1000h

    // addition/subtraction: time_point +/- duration --> time_point
    output_tp_hours(tp1 + 24h);  // 1970-07-29 10:00:00
    output_tp_hours(tp1 - 24h);  // 1970-07-27 10:00:00

    // auto foo = tp1 + tp2;  // error, addition of time_points is not allowed
}

void to_duration()
{
    const std::chrono::time_point<std::chrono::system_clock, std::chrono::hours> tp{10h};
    const std::chrono::hours dur = tp.time_since_epoch();

    output_hours(dur);  // 10h
}

int main()
{
    conversion();
    arithmetic();
    to_duration();
}
