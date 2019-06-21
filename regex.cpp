#include <iostream>
#include <string>
#include <vector>
#include <regex>

int main()
{
    std::string text{"Dies ist ein Test."};
    std::smatch m;

    std::regex re1{R"(.*(e).*)"};

    if (std::regex_match(text, m, re1))
        for (int i=0; i<m.size(); ++i)
            std::cout << "re1 MATCH " << i << ": \"" << m[i] << "\", position=" << m.position() << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;

    std::regex re2{R"((e))"};

    if (std::regex_search(text, m, re2))
        for (int i=0; i<m.size(); ++i)
            std::cout << "re2 MATCH " << i << ": \"" << m[i] << "\", position=" << m.position() << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;

    std::vector<std::string> lines{
        "[05822AE4 | 2019-06-17 06:59:03] (15828) http://contiview.site/cmd.php [co_project.dialog_doc_details] RQST START",
        "[05822AE4 | 2019-06-17 06:59:03] (15828) http://contiview.site/cmd.php [co_project.dialog_doc_details] RQST END   [normal]   318 ms",
        "[001F86EA | 2009-11-02 16:05:50] (193.98.108.243:1789, 10994) /cmd.php [co_doc.details] RQST START",
        "[001F86EA | 2009-11-02 16:05:50] (193.98.108.243:1789, 10994) /cmd.php [co_doc.details] RQST END   [normal]    84 ms"
    };

    std::regex re3{R"(\[(.+) \| ([^\]]+)\] \((.+, )?(\d+)\) (.+) \[(.+)\] RQST END   \[(.+)\] *(\d+) ms)"};

    for (auto line : lines)
        if (std::regex_match(line, m, re3))
            if (m.size() > 1)
                for (int i=1; i<m.size(); ++i)
                    std::cout << "re3 MATCH " << i << ": \"" << m[i] << "\"" << std::endl;
}
