#include <iostream>
#include <stdexcept>

void generic_exception()
{
    try {
        throw std::exception{};
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

void exception_with_error_message()
{
    try {
        throw std::runtime_error{"something happened"};
    } catch (std::runtime_error& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

void catch_all()
{
    try {
        throw std::runtime_error{"catch all"};
    } catch (std::overflow_error& e) {
        std::cout << "exception: " << e.what() << std::endl;
    } catch (std::range_error& e) {
        std::cout << "exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "catch all" << std::endl;
    }
}

void rethrow()
{
    try {
        try {
            throw std::runtime_error{"rethrow"};
        } catch (...) {
            throw;
        }
    } catch (std::runtime_error& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
}

int main()
{
    generic_exception();
    exception_with_error_message();
    catch_all();
    rethrow();
}
