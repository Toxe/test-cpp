#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
class ValueRangeObserver {
public:
    ValueRangeObserver(const std::string name) : name_{name} {}
    ValueRangeObserver(const std::string name, const T value) : name_{name}, min_{value}, max_{value} {}
    ~ValueRangeObserver() { std::cout << name_ << "(" << typeid(T).name() << ") min: " << min_ << ", max: " << max_ << std::endl; }
    void update(const T value) noexcept {
        min_ = std::min(value, min_);
        max_ = std::max(value, max_);
    }
private:
    std::string name_;
    T min_ = std::numeric_limits<T>::max();
    T max_ = std::numeric_limits<T>::min();
};

int main()
{
    ValueRangeObserver<float> ob_foo{"foo"};

    float foo;

    for (int i = 1; i <= 10; ++i) {
        foo = (100.0f * i) / 3.0f;
        ob_foo.update(foo);
    }
}
