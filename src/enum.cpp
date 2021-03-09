#include <iostream>

enum class Error {
    AllocMemory = 1,
    EvalArgs,
    LoadGradient,
    SaveImage,
    GetTime
};

int main()
{
    Error e = Error::LoadGradient;

    std::cout << static_cast<int>(e) << std::endl;
}
