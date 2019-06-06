#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> tokens{"aaa", "bbb", "ccc"};
    std::ofstream out("fstream_test.txt");

    for (auto s : tokens)
        out << s << "\n";

    out.close();
    return 0;
}
