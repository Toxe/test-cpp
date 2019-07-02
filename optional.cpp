#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> read_word(bool fake_error=false)
{
    if (fake_error)
        return {};  // oh no, an error...

    return "success";
}

std::optional<int> read_int(bool fake_error=false)
{
    if (fake_error)
        return std::nullopt;  // oh no, an error...

    return 42;
}

int main()
{
    auto word1 = read_word();
    auto word2 = read_word(true);

    std::cout << "next word: \"" << *word1 << "\"" << std::endl;
    std::cout << "next word: \"" << *word2 << "\"" << std::endl;

    std::cout << "word1 " << (word1.has_value() ? "has a value" : "has NO value") << std::endl;
    std::cout << "word2 " << (word2.has_value() ? "has a value" : "has NO value") << std::endl;

    std::cout << "value_or(): \"" << word1.value_or("error") << "\"" << std::endl;
    std::cout << "value_or(): \"" << word2.value_or("error") << "\"" << std::endl;

    auto i1 = read_int();
    auto i2 = read_int(true);

    try {
        std::cout << "next int: " << i1.value() << std::endl;
        std::cout << "next int: " << i2.value() << std::endl;
    } catch (...) {
        std::cout << "no value" << std::endl;
    }

    std::cout << "i1 " << (i1 != std::nullopt ? "has a value" : "has NO value") << std::endl;
    std::cout << "i2 " << (i2 != std::nullopt ? "has a value" : "has NO value") << std::endl;
}
