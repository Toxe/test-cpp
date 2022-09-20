#include <iostream>
#include <memory>

class NullStreamBuffer : public std::streambuf {
protected:
    virtual int_type overflow(int_type c) override
    {
        return c;
    }
};

void discard_output(std::ostream& strm)
{
    // use unique pointer to automatically restore the original stream buffer at the end
    auto del = [&](std::streambuf* p) { strm.rdbuf(p); };
    std::unique_ptr<std::streambuf, decltype(del)> orig_buffer(strm.rdbuf(), del);

    NullStreamBuffer null_streambuf;
    strm.rdbuf(&null_streambuf);

    strm << "discarded output\n";
}

int main()
{
    std::cout << "output 1 to std::cout\n";
    discard_output(std::cout);
    std::cout << "output 2 to std::cout\n";
}
