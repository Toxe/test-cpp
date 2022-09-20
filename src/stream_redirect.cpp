#include <fstream>
#include <iostream>
#include <memory>

void redirect_simple(std::ostream& strm)
{
    std::ofstream file("redirect_simple.txt");
    auto* orig_buffer = strm.rdbuf(file.rdbuf());  // redirect output into file

    strm << "output 1 to redirect_simple.txt (strm)\n";
    file << "output 2 to redirect_simple.txt (file)\n";

    strm.rdbuf(orig_buffer);  // restore old stream buffer
}

void redirect_improved(std::ostream& strm)
{
    // use unique pointer to automatically restore the original stream buffer at the end
    auto del = [&](std::streambuf* p) { strm.rdbuf(p); };
    std::unique_ptr<std::streambuf, decltype(del)> orig_buffer(strm.rdbuf(), del);

    std::ofstream file("redirect_improved.txt");
    strm.rdbuf(file.rdbuf());  // redirect output into file

    strm << "output 1 to redirect_improved.txt (strm)\n";
    file << "output 2 to redirect_improved.txt (file)\n";
}

int main()
{
    std::cout << "output 1 to std::cout\n";
    redirect_simple(std::cout);
    std::cout << "output 2 to std::cout\n";

    std::cout << "output 3 to std::cout\n";
    redirect_improved(std::cout);
    std::cout << "output 4 to std::cout\n";
}
