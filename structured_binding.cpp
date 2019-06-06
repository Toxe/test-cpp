#include <iostream>
#include <string>

struct Value {
    std::string name;
    int value1;
    float value2;
};

Value return_value()
{
    return {"value", 3, 0.7f};
}

std::tuple<std::string, int, float> return_tuple()
{
    return std::make_tuple("tuple", 5, 0.2f);
}

int main()
{
    auto v1 = return_value();
    auto [name, a, b] = return_value();
    auto [tn, ta, tb] = return_tuple();

    std::cout << v1.name << ": " << v1.value1 << ", " << v1.value2 << "\n";
    std::cout << name << ": " << a << ", " << b << "\n";
    std::cout << tn << ": " << ta << ", " << tb << "\n";
}
