#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std::literals::chrono_literals;

using float_millisecond = std::chrono::duration<float, std::milli>;
using float_second = std::chrono::duration<float>;

void output_float_seconds(const float_second s)
{
    std::cout << std::setprecision(8) << s.count() << "s\n";
}

void output_float_milliseconds(const float_millisecond ms)
{
    std::cout << std::setprecision(8) << ms.count() << "ms\n";
}

// implicit conversions FROM any precision TO floating-point representations (without using duration_cast)
void implicit_floating_point_conversions()
{
    float_millisecond ms{2500};
    float_second s{5};

    output_float_milliseconds(ms);  // 2500ms
    output_float_seconds(ms);  // 2.5s

    output_float_milliseconds(s);  // 5000ms
    output_float_seconds(s);  // 5s

    // implicit conversion of microseconds
    output_float_milliseconds(333us);  // 0.333ms
    output_float_seconds(333us);  // 0.000333s

    // implicit conversion of minutes
    output_float_milliseconds(2min);  // 120000ms
    output_float_seconds(2min);  // 120s

    output_float_seconds(2min + 5s + 10ms + float_millisecond{666us});  // 125.01067s
}

int main()
{
    implicit_floating_point_conversions();
}
